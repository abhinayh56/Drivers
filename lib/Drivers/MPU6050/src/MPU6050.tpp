#include "MPU6050.h"

template <typename T_I2C_bus>
MPU6050<T_I2C_bus>::MPU6050(T_I2C_bus *i2c_bus, uint8_t address) : i2c_bus(i2c_bus), address(address)
{
}

template <typename T_I2C_bus>
void MPU6050<T_I2C_bus>::init()
{
    set_bit_val((uint8_t)MPU6050_INFO::REGISTER::PWR_MGMT_1, (uint8_t)BIT::MASK8::BITM1_6, (uint8_t)(uint8_t)SIX, (uint8_t)0);
}

template <typename T_I2C_bus>
void MPU6050<T_I2C_bus>::config()
{
    set_bit_val((uint8_t)MPU6050_INFO::REGISTER::CONFIG, (uint8_t)BIT::MASK8::BITM3_0, (uint8_t)ZERO, (uint8_t)MPU6050_INFO::BIT_FLAGS::CONFIG::DLPF_CFG_0);
    set_bit_val((uint8_t)MPU6050_INFO::REGISTER::PWR_MGMT_1, (uint8_t)BIT::MASK8::BITM3_0, (uint8_t)ZERO, (uint8_t)MPU6050_INFO::BIT_FLAGS::PWR_MGMT_1::CLKSEL_1);
    set_bit_val((uint8_t)MPU6050_INFO::REGISTER::SMPLRT_DIV, (uint8_t)BIT::MASK8::BITM8_0, (uint8_t)ZERO, (uint8_t)0);
    set_bit_val((uint8_t)MPU6050_INFO::REGISTER::GYRO_CONFIG, (uint8_t)BIT::MASK8::BITM2_3, (uint8_t)THREE, (uint8_t)MPU6050_INFO::BIT_FLAGS::GYRO_CONFIG::FS_SEL_2);
    set_bit_val((uint8_t)MPU6050_INFO::REGISTER::ACCEL_CONFIG, (uint8_t)BIT::MASK8::BITM2_3, (uint8_t)THREE, (uint8_t)MPU6050_INFO::BIT_FLAGS::ACCEL_CONFIG::AFS_SEL_2);
}

template <typename T_I2C_bus>
void MPU6050<T_I2C_bus>::get_acc(int16_t *ac_x, int16_t *ac_y, int16_t *ac_z)
{
    i2c_bus->receive_data(address, (uint8_t)MPU6050_INFO::REGISTER::ACCEL_XOUT_H, buff, (uint8_t)6);
    *ac_x = ((int16_t)buff[0] << 8) | buff[1];
    *ac_y = ((int16_t)buff[2] << 8) | buff[3];
    *ac_z = ((int16_t)buff[4] << 8) | buff[5];
}

template <typename T_I2C_bus>
void MPU6050<T_I2C_bus>::get_gyro(int16_t *gy_x, int16_t *gy_y, int16_t *gy_z)
{
    i2c_bus->receive_data(address, (uint8_t)MPU6050_INFO::REGISTER::GYRO_XOUT_H, buff, (uint8_t)6);
    *gy_x = ((int16_t)buff[0] << 8) | buff[1];
    *gy_y = ((int16_t)buff[2] << 8) | buff[3];
    *gy_z = ((int16_t)buff[4] << 8) | buff[5];
}

template <typename T_I2C_bus>
uint8_t MPU6050<T_I2C_bus>::get_temp()
{
    i2c_bus->receive_data(address, (uint8_t)MPU6050_INFO::REGISTER::TEMP_OUT_H, buff, (uint8_t)2);
    return ((int16_t)buff[0] << 8) | buff[1];
}

template <typename T_I2C_bus>
void MPU6050<T_I2C_bus>::get_data(int16_t *ac_x, int16_t *ac_y, int16_t *ac_z, int16_t *temp, int16_t *gy_x, int16_t *gy_y, int16_t *gy_z)
{
    i2c_bus->receive_data((uint8_t)address, (uint8_t)MPU6050_INFO::REGISTER::ACCEL_XOUT_H, buff, (uint8_t)14);
    *ac_x = ((int16_t)buff[0] << 8) | buff[1];
    *ac_y = ((int16_t)buff[2] << 8) | buff[3];
    *ac_z = ((int16_t)buff[4] << 8) | buff[5];
    *temp = ((int16_t)buff[6] << 8) | buff[7];
    *gy_x = ((int16_t)buff[8] << 8) | buff[9];
    *gy_y = ((int16_t)buff[10] << 8) | buff[11];
    *gy_z = ((int16_t)buff[12] << 8) | buff[13];
}

template <typename T_I2C_bus>
void MPU6050<T_I2C_bus>::set_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0, uint8_t bit_val)
{
    uint8_t register_val = i2c_bus->receive_data(address, reg);
    register_val = (register_val & (~bit_mask)) | (bit_val << bit_lcn_0);
    i2c_bus->send_data(address, reg, register_val);
}

template <typename T_I2C_bus>
uint8_t MPU6050<T_I2C_bus>::get_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0)
{
    return ((i2c_bus->receive_data(address, reg)) & bit_mask) >> bit_lcn_0;
}
