#ifndef HAL_I2C_H
#define HAL_I2C_H

#ifdef ARDUINO
#include "../HAL_arduino/I2C_bus/I2C_bus.tpp"

#elif defined(ESP32)
#include ""

#elif defined(TEENSY_4_1)
#include ""

#else
#include ""
#endif

#endif // HAL_I2C_H
