#ifndef MS5611_H
#define MS5611_H

#include <stdint.h>
#include "../Utility/Utility.h"
#include "MS5611_reg.h"

template <typename T_I2C_bus>
class MS5611
{
    public:
        MS5611(T_I2C_bus* i2c_bus_, uint8_t address_);
        void init();
        void config(uint16_t osr_press_, uint16_t osr_temp_, uint16_t time_us_sample_, uint8_t p_t_ratio_);

        void get_data(double* press, double* temp);

    private:
        T_I2C_bus* i2c_bus;
        uint8_t address;

        uint16_t OSR_P = 4096;
        uint16_t OSR_T = 4096;

        uint8_t COMMAND_P = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D1_OSR_4096;
        uint8_t COMMAND_T = (uint8_t)MS5611_INFO::COMMAND::CONVERT_D2_OSR_4096;

        uint16_t C1 = 0;
        uint16_t C2 = 0;
        uint16_t C3 = 0;
        uint16_t C4 = 0;
        uint16_t C5 = 0;
        uint16_t C6 = 0;

        uint32_t D1 = 0;
        uint32_t D2 = 0;

        int32_t dT = 0;
        int32_t TEMP = 0;

        int64_t OFF = 0;
        int64_t SENS = 0;
        int32_t P = 0;

        uint16_t time_us_max_osr_4096 = 10000;
        uint16_t time_us_sample = 2000;
        uint16_t time_us_wait = time_us_max_osr_4096;
        uint16_t time_us_current = 0;

        bool trigger_point = true;
        bool frame_start = true;
        uint8_t p_t_ratio = 5;
        uint8_t p_t_counter = 0;

        void reset();
        void set_osr(uint16_t osr_press_, uint16_t osr_temp_);
        void read_prom();
        void d1_conversion();
        void d2_conversion();
        uint32_t read_adc();
        void cal_temp();
        void cal_temp_compensated_pressure();
        void second_order_temperature_compensation();
};

#include "MS5611.tpp"

#endif
