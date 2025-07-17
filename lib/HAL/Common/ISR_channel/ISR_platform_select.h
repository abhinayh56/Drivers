#ifndef ISR_PLATFORM_SELECT_H
#define ISR_PLATFORM_SELECT_H

#ifdef ARDUINO_TEENSY41
#include "../../HAL_teensy/ISR_channel/ISR_channel.tpp"

#elif defined(ARDUINO_ESP32)
#include ""

#elif defined(ARDUINO)
#include "../../HAL_arduino/ISR_channel/ISR_channel.tpp"

#else
#error "No I2C implementation defined for this platform"

#endif

#endif // ISR_PLATFORM_SELECT_H
