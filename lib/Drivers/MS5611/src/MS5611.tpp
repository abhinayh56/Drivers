#include "MS5611.h"

template <typename T_I2C_bus>
MS5611<T_I2C_bus>::MS5611(T_I2C_bus* i2c_bus_, uint8_t address_): i2c_bus(i2c_bus_), address(address_)
{
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::init()
{
    reset();
    // wait 100 ms
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::config(uint16_t osr_press_, uint16_t osr_temp_, uint16_t time_us_sample_, uint8_t p_t_ratio_)
{
    time_us_sample = time_us_sample_;
    p_t_ratio = p_t_ratio_;
    set_osr(osr_press_, osr_temp_);
    read_prom();
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::get_data(double* press, double* temp)
{
    if(time_us_current >= time_us_wait)
    {
        trigger_point = true;
        time_us_current = 0;
    }

    if(trigger_point==true)
    {
        if(frame_start==true)
        {
            if(p_t_counter==0)
            {
                d2_conversion(); // request temperature
                time_us_wait = (uint16_t)((double)time_us_max_osr_4096 * (double)OSR_T / 4096.0);
            }
            else if(p_t_counter == 1)
            {
                D2 = read_adc(); // get temperature
                d1_conversion(); // request pressure
                time_us_wait = (uint16_t)((double)time_us_max_osr_4096 * (double)OSR_P / 4096.0);
            }
            else if(p_t_counter == (p_t_ratio+1))
            {
                D1 = read_adc(); // get pressure
                d2_conversion(); // request temperature
                time_us_wait = (uint16_t)((double)time_us_max_osr_4096 * (double)OSR_T / 4096.0);
            }
            else
            {
                D1 = read_adc(); // get pressure
                d1_conversion(); // request pressure
                time_us_wait = (uint16_t)((double)time_us_max_osr_4096 * (double)OSR_P / 4096.0);
            }
            frame_start = false;
        }
        else
        {
            if(p_t_counter == 1)
            {
                D2 = read_adc(); // get temperature
                d1_conversion(); // request pressure
                time_us_wait = (uint16_t)((double)time_us_max_osr_4096 * (double)OSR_P / 4096.0);
            }
            else if(p_t_counter == (p_t_ratio+1))
            {
                D1 = read_adc(); // get pressure
                d2_conversion(); // request temperature
                time_us_wait = (uint16_t)((double)time_us_max_osr_4096 * (double)OSR_T / 4096.0);
            }
            else
            {
                D1 = read_adc(); // get pressure
                d1_conversion(); // request pressure
                time_us_wait = (uint16_t)((double)time_us_max_osr_4096 * (double)OSR_P / 4096.0);
            }
        }

        p_t_counter++;
        if(p_t_counter>=p_t_ratio+2)
        {
            p_t_counter = 1;
        }

        trigger_point = false;
    }

    time_us_current += time_us_sample;
    
    cal_temp();
    cal_temp_compensated_pressure();

    *press = 0.01 * P;
    *temp  = 0.01 * TEMP;
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::set_osr(uint16_t osr_press_, uint16_t osr_temp_)
{
    OSR_P = osr_press_;
    OSR_T = osr_temp_;

    switch(osr_press_)
    {
        case 256:
            COMMAND_P = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D1_OSR_256;
            break;
        case 512:
            COMMAND_P = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D1_OSR_512;
            break;
        case 1024:
            COMMAND_P = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D1_OSR_1024;
            break;
        case 2048:
            COMMAND_P = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D1_OSR_2048;
            break;
        case 4096:
            COMMAND_P = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D1_OSR_4096;
            break;
        default:
            COMMAND_P = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D1_OSR_4096;
    }

    switch(osr_temp_)
    {
        case 256:
            COMMAND_T = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D2_OSR_256;
            break;
        case 512:
            COMMAND_T = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D2_OSR_512;
            break;
        case 1024:
            COMMAND_T = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D2_OSR_1024;
            break;
        case 2048:
            COMMAND_T = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D2_OSR_2048;
            break;
        case 4096:
            COMMAND_T = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D2_OSR_4096;
            break;
        default:
            COMMAND_T = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D2_OSR_4096;
    }
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::reset()
{
    i2c_bus->send_data(address, (uint8_t)MS5611_INFO::COMMAND::RESET);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::read_prom()
{
    uint8_t buff[2];
    i2c_bus->receive_data(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_1, buff, 2);
    C1 = ((uint16_t)buff[0] << 8) | buff[1];
    i2c_bus->receive_data(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_2, buff, 2);
    C2 = ((uint16_t)buff[0] << 8) | buff[1];
    i2c_bus->receive_data(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_3, buff, 2);
    C3 = ((uint16_t)buff[0] << 8) | buff[1];
    i2c_bus->receive_data(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_4, buff, 2);
    C4 = ((uint16_t)buff[0] << 8) | buff[1];
    i2c_bus->receive_data(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_5, buff, 2);
    C5 = ((uint16_t)buff[0] << 8) | buff[1];
    i2c_bus->receive_data(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_6, buff, 2);
    C6 = ((uint16_t)buff[0] << 8) | buff[1];
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::d1_conversion()
{
    i2c_bus->send_data(address, COMMAND_P);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::d2_conversion()
{
    i2c_bus->send_data(address, COMMAND_T);
}

template <typename T_I2C_bus>
uint32_t MS5611<T_I2C_bus>::read_adc()
{
    uint8_t buff[3];
    i2c_bus->receive_data(address, (uint8_t)(uint8_t)MS5611_INFO::COMMAND::ADC_READ, buff, 3);
    uint32_t adc_val = ((uint32_t)buff[0])<<16 | ((uint32_t)buff[1])<<8 | buff[2];
    return adc_val;
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::cal_temp()
{
    dT = D2 - (int32_t)C5 * 256;
    TEMP = 2000 + (int32_t)((dT*(int32_t)C6)/8388608.0);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::cal_temp_compensated_pressure()
{
    OFF  = (int64_t)C2*65536 + (int64_t)(((int64_t)C4*(int64_t)dT)/128.0);
    SENS = (int64_t)C1*32768 + (int64_t)(((int64_t)C3*(int64_t)dT)/256.0);
    second_order_temperature_compensation();
    P = (int64_t)(((D1*SENS)/2097152.0 - OFF) / 32768.0);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::second_order_temperature_compensation()
{
    double T2 = 0;
    double OFF2 = 0;
    double SENS2 = 0;

    if(TEMP<2000)
    {
        T2 = (double)dT*(double)dT / 2147483648.0;
        OFF2 = 5.0*(TEMP-2000.0)*(TEMP-2000.0)/2.0;
        SENS2 = 5.0*(TEMP-2000.0)*(TEMP-2000.0)/4.0;

        if(TEMP<-1500)
        {
            OFF2 = OFF2 + 7.0*(TEMP+1500.0)*(TEMP+1500.0);
            SENS2 = SENS2 + 11.0*((TEMP+1500.0)*(TEMP+1500.0))/2.0;
        }
    }
    else
    {
        T2 = 0;
        OFF2 = 0;
        SENS2 = 0;
    }

    TEMP = (int32_t)(TEMP - T2);
    OFF = (int64_t)(OFF - OFF2);
    SENS = (int64_t)(SENS - SENS2);
}
