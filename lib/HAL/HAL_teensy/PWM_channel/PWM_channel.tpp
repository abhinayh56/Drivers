#include "../../Common/PWM_channel/PWM_channel.h"

template <typename T_PWM>
PWM_channel<T_PWM>::PWM_channel(T_PWM *pwm_)
{
}

template <typename T_PWM>
PWM_channel<T_PWM>::~PWM_channel()
{
}

template <typename T_PWM>
void PWM_channel<T_PWM>::init()
{
}

template <typename T_PWM>
bool PWM_channel<T_PWM>::config(uint32_t frequency_hz_)
{
}

template <typename T_PWM>
void PWM_channel<T_PWM>::set_duty(double duty_percent_)
{
}

template <typename T_PWM>
void PWM_channel<T_PWM>::set_pwm(uint32_t pwm_us_)
{
}
