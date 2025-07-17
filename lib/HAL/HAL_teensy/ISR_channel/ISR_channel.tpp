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
bool ISR_channel<T_ISR_channel>::config(uint8_t isr_pin_, void (*isr_function)(), int transition, int input_select)
{
    isr_pin = isr_pin_;

    if (input_select == ISR_channel_param::Input_type::TYPE_DISABLE)
    {
        pinMode(isr_pin, INPUT_DISABLE);
    }
    else if (input_select == ISR_channel_param::Input_type::TYPE_DEFAULT)
    {
        pinMode(isr_pin, INPUT);
    }
    else if (input_select == ISR_channel_param::Input_type::TYPE_PULLDOWN)
    {
        pinMode(isr_pin, INPUT_PULLDOWN);
    }
    else if (input_select == ISR_channel_param::Input_type::TYPE_PULLUP)
    {
        pinMode(isr_pin, INPUT_PULLUP);
    }
    else
    {
        pinMode(isr_pin, INPUT);
    }

    if (transition == ISR_channel_param::Trigger::EDGE_RISING)
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, RISING);
    }
    else if (transition == ISR_channel_param::Trigger::EDGE_FALLING)
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, FALLING);
    }
    else if (transition == ISR_channel_param::Trigger::EDGE_CHANGING)
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, CHANGE);
    }
    else if (transition == ISR_channel_param::Trigger::EDGE_HIGH)
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, HIGH);
    }
    else if (transition == ISR_channel_param::Trigger::EDGE_LOW)
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, LOW);
    }
    else
    {
        attachInterrupt(digitalPinToInterrupt(isr_pin), isr_function, CHANGE);
    }

    return true;
}
