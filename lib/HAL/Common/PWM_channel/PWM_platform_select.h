#ifndef PWM_PLATFORM_SELECT_H
#define PWM_PLATFORM_SELECT_H

#ifdef ARDUINO_TEENSY41
#include "../../HAL_teensy/PWM_channel/PWM_channel.tpp"

#elif defined(ARDUINO_ESP32)
#include ""

#elif defined(ARDUINO)
#include "../../HAL_arduino/PWM_channel/PWM_channel.tpp"

#else
#error "No PWM_channel implementation defined for this platform"

#endif

#endif // PWM_PLATFORM_SELECT_H
