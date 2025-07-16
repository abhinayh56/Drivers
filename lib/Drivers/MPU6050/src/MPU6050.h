#ifndef MPU6050_H
#define MPU6050_H

#include <stdint.h>
#include "../Utility/Utility.h"
#include "MPU6050_reg.h"

template <typename T_I2C_bus>
class MPU6050
{
public:
    MPU6050(T_I2C_bus *i2c_bus, uint8_t address);
    void init();
    void config();

    void get_acc(int16_t *ac_x, int16_t *ac_y, int16_t *ac_z);
    void get_gyro(int16_t *gy_x, int16_t *gy_y, int16_t *gy_z);
    uint8_t get_temp();
    void get_data(int16_t *ac_x, int16_t *ac_y, int16_t *ac_z, int16_t *temp, int16_t *gy_x, int16_t *gy_y, int16_t *gy_z);

private:
    T_I2C_bus *i2c_bus;
    uint8_t address;
    uint8_t buff[14];

    void set_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0, uint8_t bit_val);
    uint8_t get_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0);
};

#include "MPU6050.tpp"

#endif
