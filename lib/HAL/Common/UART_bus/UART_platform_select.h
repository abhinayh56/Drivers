#ifndef UART_PLATFORM_SELECT_H
#define UART_PLATFORM_SELECT_H

#ifdef ARDUINO_TEENSY41
#include "../../HAL_teensy/UART_bus/UART_bus.tpp"

#elif defined(ARDUINO_ESP32)
#include ""

#elif defined(ARDUINO)
#include "../../HAL_arduino/UART_bus/UART_bus.tpp"

#else
#error "No UART implementation defined for this platform"

#endif

#endif // UART_PLATFORM_SELECT_H
