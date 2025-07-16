#ifndef HMC5883_REG
#define HMC5883_REG

#include <stdint.h>

namespace HMC5883_INFO
{
    enum class ADDR
    {
        I2C = 0x1E,
        I2C_DEFAULT = I2C
    };

    enum class REGISTER : uint8_t
    {
        CONFIG_A         = 0x00,
        CONFIG_B         = 0x01,
        MODE             = 0x02,
        DATA_OUT_X_MSB   = 0x03,
        DATA_OUT_X_LSB   = 0x04,
        DATA_OUT_Z_MSB   = 0x05,
        DATA_OUT_Z_LSB   = 0x06,
        DATA_OUT_Y_MSB   = 0x07,
        DATA_OUT_Y_LSB   = 0x08,
        STATUS           = 0x09,
        IDENTIFICATION_A = 0x0A,
        IDENTIFICATION_B = 0x0B,
        IDENTIFICATION_C = 0x0C
    };
    namespace BIT_FLAGS
    {
        enum class CONFIG_A : uint8_t
        {
            MA_0 = 0,
            MA_1 = 1,
            MA_2 = 2,
            MA_3 = 3,
            DO_0 = 0,
            DO_1 = 1,
            DO_2 = 2,
            DO_3 = 3,
            DO_4 = 4,
            DO_5 = 5,
            DO_6 = 6,
            DO_7 = 7,
            MS_0 = 0,
            MS_1 = 1,
            MS_2 = 2,
            MS_3 = 3
        };

        enum class CONFIG_B : uint8_t
        {
            GN_0 = 0,
            GN_1 = 1,
            GN_2 = 2,
            GN_3 = 3,
            GN_4 = 4,
            GN_5 = 5,
            GN_6 = 6,
            GN_7 = 7
        };

        enum class MODE : uint8_t
        {
            HS_0 = 0,
            HS_1 = 1,
            MD_0 = 0,
            MD_1 = 1,
            MD_2 = 2,
            MD_3 = 3
        };

        enum class STATUS : uint8_t
        {
            LOCK_0 = 0,
            LOCK_1 = 1,
            RDY_0  = 0,
            RDY_1  = 1
        };

        enum class IDENTIFICATION_A : uint8_t
        {
            IRA = (1<<6) | (1<<3)
        };

        enum class IDENTIFICATION_B : uint8_t
        {
            IRB = (1<<5) | (1<<4) | (1<<2)
        };

        enum class IDENTIFICATION_C : uint8_t
        {
            IRC = (1<<5) | (1<<4) | (1<<1) | (1<<0)
        };
    }
}

#endif
