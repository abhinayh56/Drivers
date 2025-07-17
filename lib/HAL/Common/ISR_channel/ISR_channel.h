#ifndef ISR_CHANNEL_H
#define ISR_CHANNEL_H

#include <stdint.h>

namespace ISR_channel_param
{
    enum Trigger : uint8_t
    {
        EDGE_RISING = 0,
        EDGE_FALLING = 1,
        EDGE_CHANGING = 2,
        EDGE_HIGH = 3,
        EDGE_LOW = 4
    };

    enum Input_type : uint8_t
    {
        TYPE_DISABLE = 0,
        TYPE_DEFAULT = 1,
        TYPE_PULLDOWN = 2,
        TYPE_PULLUP = 3
    };
}

template <typename T_ISR_channel>
class ISR_channel
{
public:
    ISR_channel(T_ISR_channel *isr_ch_);
    ~ISR_channel();

    void init();

    bool config(uint8_t isr_pin_, void (*isr_function)(), int transition, int = false);

private:
    T_ISR_channel *isr_ch;
    uint8_t isr_pin;
};

#include "ISR_platform_select.h"

#endif // ISR_CHANNEL_H
