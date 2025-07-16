#include "HMC5883.h"

template <typename T_I2C_bus>
HMC5883<T_I2C_bus>::HMC5883(T_I2C_bus* i2c_bus, uint8_t address) : i2c_bus(i2c_bus), address(address)
{
}

template <typename T_I2C_bus>
void HMC5883<T_I2C_bus>::init()
{
    set_bit_val((uint8_t)HMC5883_INFO::REGISTER::MODE, (uint8_t)BIT::MASK8::BITM1_7,(uint8_t)SEVEN,(uint8_t)1); //I2C speed
    set_bit_val((uint8_t)HMC5883_INFO::REGISTER::CONFIG_A, (uint8_t)BIT::MASK8::BITM1_7,(uint8_t)SEVEN,(uint8_t)0); // in datasheet
    set_bit_val((uint8_t)HMC5883_INFO::REGISTER::CONFIG_B, (uint8_t)BIT::MASK8::BITM5_0,(uint8_t)ZERO,(uint8_t)0); // in datasheet
}

template <typename T_I2C_bus>
void HMC5883<T_I2C_bus>::config()
{
    set_bit_val((uint8_t)HMC5883_INFO::REGISTER::MODE, (uint8_t)BIT::MASK8::BITM2_0,(uint8_t)ZERO,(uint8_t)0); // continuous mode
    set_bit_val((uint8_t)HMC5883_INFO::REGISTER::CONFIG_A, (uint8_t)BIT::MASK8::BITM3_2,(uint8_t)TWO,(uint8_t)6); // data output rate
    set_bit_val((uint8_t)HMC5883_INFO::REGISTER::CONFIG_A, (uint8_t)BIT::MASK8::BITM2_5,(uint8_t)FIVE,(uint8_t)0); // average window
}

template <typename T_I2C_bus>
void HMC5883<T_I2C_bus>::get_mag(int16_t* mg_x, int16_t* mg_y, int16_t* mg_z)
{
    i2c_bus->receive_data(address,(uint8_t)HMC5883_INFO::REGISTER::DATA_OUT_X_MSB, buff, (uint8_t)6);
    *mg_x = ((int16_t)buff[0] << 8) | buff[1];
    *mg_z = ((int16_t)buff[2] << 8) | buff[3];
    *mg_y = ((int16_t)buff[4] << 8) | buff[5];
}

template <typename T_I2C_bus>
void HMC5883<T_I2C_bus>::get_data(int16_t* mg_x, int16_t* mg_y, int16_t* mg_z)
{
    i2c_bus->receive_data(address,(uint8_t)HMC5883_INFO::REGISTER::DATA_OUT_X_MSB, buff, (uint8_t)6);
    *mg_x = ((int16_t)buff[0] << 8) | buff[1];
    *mg_z = ((int16_t)buff[2] << 8) | buff[3];
    *mg_y = ((int16_t)buff[4] << 8) | buff[5];
}

template <typename T_I2C_bus>
void HMC5883<T_I2C_bus>::set_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0, uint8_t bit_val)
{
    uint8_t register_val = i2c_bus->receive_data(address, reg);
    register_val = (register_val & (~bit_mask)) | (bit_val<<bit_lcn_0);
    i2c_bus->send_data(address, reg, register_val);
}

template <typename T_I2C_bus>
uint8_t HMC5883<T_I2C_bus>::get_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0)
{
    return ((i2c_bus->receive_data(address, reg)) & bit_mask) >> bit_lcn_0;
}