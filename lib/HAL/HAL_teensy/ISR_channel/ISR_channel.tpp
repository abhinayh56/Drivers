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

    if (mode == ISR_channel_param::Trigger::EDGE_RISING)
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, RISING)
    }
    else if (mode == ISR_channel_param::Trigger::EDGE_FALLING)
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, FALLING)
    }
    else if (mode == ISR_channel_param::Trigger::EDGE_CHANGING)
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, CHANGE)
    }
    else if (mode == ISR_channel_param::Trigger::EDGE_HIGH)
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, HIGH)
    }
    else if (mode == ISR_channel_param::Trigger::EDGE_LOW)
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, LOW)
    }
    else
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, CHANGE)
    }
}
