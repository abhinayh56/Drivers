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
    bool config(uint32_t frequency_hz_);
    void set_duty(double duty_percent_);
    void set_pwm(uint32_t pwm_us_);

private:
    T_PWM *pwm;
};

#include "PWM_platform_select.h"

#endif // PWM_CHANNEL_H
