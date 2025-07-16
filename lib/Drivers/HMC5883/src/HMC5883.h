#ifndef HMC5883_H
#define HMC5883_H

#include <stdint.h>
#include "../Utility/Utility.h"
#include "HMC5883_reg.h"

template <typename T_I2C_bus>
class HMC5883
{
public:
    HMC5883(T_I2C_bus *i2c_bus_, uint8_t address_);
    void init();
    void config();

    void get_mag(int16_t *mg_x, int16_t *mg_y, int16_t *mg_z);
    void get_data(int16_t *mg_x, int16_t *mg_y, int16_t *mg_z);

private:
    T_I2C_bus *i2c_bus;
    uint8_t address;
    uint8_t buff[6];

    void set_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0, uint8_t bit_val);
    uint8_t get_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0);
};

#include "HMC5883.tpp"

#endif
