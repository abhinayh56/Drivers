#include "../../Common/ISR_channel/ISR_channel.h"
#include <Arduino.h>

template <typename T_ISR_channel>
ISR_channel<T_ISR_channel>::ISR_channel(T_ISR_channel *isr_ch_) : isr_ch(isr_ch_)
{
}

template <typename T_ISR_channel>
ISR_channel<T_ISR_channel>::~ISR_channel()
{
}

template <typename T_ISR_channel>
void ISR_channel<T_ISR_channel>::init()
{
}

template <typename T_ISR_channel>
bool ISR_channel<T_ISR_channel>::config(uint8_t isr_pin_, void (*isr_function)(), int mode)
{
    isr_pin = isr_pin_;
    pinMode(isr_pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, mode)
}

template <typename T_ISR_channel>
void ISR_channel<T_ISR_channel>::isr_fun()
{
}