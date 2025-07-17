#ifndef PWM_CHANNEL_H
#define PWM_CHANNEL_H

#include <stdint.h>

template <typename T_PWM>
class PWM_channel
{
public:
    PWM_channel(T_PWM *pwm_);
    ~PWM_channel();

    void init();
    bool config(uint8_t pwm_ch_, uint32_t frequency_hz_, uint32_t resolution_bit_);
    void set_pwm_us(double pwm_us_);
    void set_duty(double duty_percent_);

private:
    T_PWM *pwm;
    uint8_t pwm_ch;
    uint32_t frequency_hz = 400;
    uint32_t resolution_bit = 15;
    double time_period_us = 2500;

    inline int32_t pwm_to_bit_val(double pwm_us);
};

#include "PWM_platform_select.h"

#endif // PWM_CHANNEL_H
