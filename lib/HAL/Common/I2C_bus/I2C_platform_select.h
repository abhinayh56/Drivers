#ifndef I2C_PLATFORM_SELECT_H
#define I2C_PLATFORM_SELECT_H

#ifdef ARDUINO_TEENSY41
#include "../../HAL_teensy/I2C_bus/I2C_bus.tpp"

#elif defined(ARDUINO_ESP32)
#include ""

#elif defined(ARDUINO)
#include "../../HAL_arduino/I2C_bus/I2C_bus.tpp"

#else
#error "No I2C implementation defined for this platform"

#endif

#endif // I2C_PLATFORM_SELECT_H
