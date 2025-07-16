#ifndef MS5611_REG
#define MS5611_REG

#include <stdint.h>

namespace MS5611_INFO
{
    enum class ADDR
    {
        I2C_1 = 0x76,
        I2C_2 = 0x77,
        I2C_DEFAULT = I2C_2
    };

    enum class COMMAND : uint8_t
    {
        RESET               = 0x1E,
        CONVERT_D1_OSR_256  = 0x40,
        CONVERT_D1_OSR_512  = 0x42,
        CONVERT_D1_OSR_1024 = 0x44,
        CONVERT_D1_OSR_2048 = 0x46,
        CONVERT_D1_OSR_4096 = 0x48,
        CONVERT_D2_OSR_256  = 0x50,
        CONVERT_D2_OSR_512  = 0x52,
        CONVERT_D2_OSR_1024 = 0x54,
        CONVERT_D2_OSR_2048 = 0x56,
        CONVERT_D2_OSR_4096 = 0x58,
        ADC_READ            = 0x00,
        PROM_READ_0         = 0xA0,
        PROM_READ_1         = 0xA2,
        PROM_READ_2         = 0xA4,
        PROM_READ_3         = 0xA6,
        PROM_READ_4         = 0xA8,
        PROM_READ_5         = 0xAA,
        PROM_READ_6         = 0xAC,
        PROM_READ_7         = 0xAE 
    };
}

#endif
