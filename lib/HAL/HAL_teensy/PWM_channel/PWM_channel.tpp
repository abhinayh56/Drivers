#include "../../Common/PWM_channel/PWM_channel.h"
#include <Arduino.h>

template <typename T_PWM>
PWM_channel<T_PWM>::PWM_channel(T_PWM *pwm_) : pwm(pwm_)
{
}

template <typename T_PWM>
PWM_channel<T_PWM>::~PWM_channel()
{
    analogWrite(pwm_ch, pwm_to_bit_val(0));
}

template <typename T_PWM>
void PWM_channel<T_PWM>::init()
{
}

template <typename T_PWM>
bool PWM_channel<T_PWM>::config(uint8_t pwm_ch_, uint32_t frequency_hz_, uint32_t resolution_bit_)
{
    pwm_ch = pwm_ch_;
    frequency_hz = frequency_hz_;
    resolution_bit = resolution_bit_;
    time_period_us = 1000000.0 / (double)frequency_hz;

    analogWriteFrequency(*pwm, frequency_hz);
    analogWriteResolution(resolution_bit);
    pinMode(pwm_ch, OUTPUT);
    analogWrite(pwm_ch, pwm_to_bit_val(0));

    return true;
}

template <typename T_PWM>
void PWM_channel<T_PWM>::set_pwm_us(double pwm_us_)
{
    if (pwm_us_ < 0.0)
    {
        pwm_us_ = 0.0;
    }
    else if (pwm_us_ >= time_period_us)
    {
        pwm_us_ = time_period_us;
    }

    analogWrite(pwm_ch, pwm_to_bit_val(pwm_us_));
}

template <typename T_PWM>
void PWM_channel<T_PWM>::set_duty(double duty_percent_)
{
    if (duty_percent_ < 0.0)
    {
        duty_percent_ = 0.0;
    }
    else if (duty_percent_ > 100.0)
    {
        duty_percent_ = 100.0;
    }

    analogWrite(pwm_ch, (double)((1 << resolution_bit) - 1) * duty_percent_ * 0.01);
}

template <typename T_PWM>
inline int32_t PWM_channel<T_PWM>::pwm_to_bit_val(double pwm_us)
{
    return ((double)((1 << resolution_bit) - 1) * pwm_us) / time_period_us;
}
