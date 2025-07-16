#include <Arduino.h>
#include "../lib/HAL/Common/PWM_channel/PWM_channel.h"

uint8_t pin_1 = 2;
uint8_t pin_2 = 3;
uint8_t pin_3 = 5;
uint8_t pin_4 = 6;

PWM_channel<uint8_t> pwm_ch_1(&pin_1);
PWM_channel<uint8_t> pwm_ch_2(&pin_2);
PWM_channel<uint8_t> pwm_ch_3(&pin_3);
PWM_channel<uint8_t> pwm_ch_4(&pin_4);

void setup()
{
    pwm_ch_1.init();
    pwm_ch_2.init();
    pwm_ch_3.init();
    pwm_ch_4.init();

    pwm_ch_1.config(400, 15);
    pwm_ch_2.config(400, 15);
    pwm_ch_3.config(400, 15);
    pwm_ch_4.config(400, 15);

    delay(10000);
}

void loop()
{
    pwm_ch_1.set_duty(50);
    pwm_ch_2.set_duty(50);
    pwm_ch_3.set_duty(50);
    pwm_ch_4.set_duty(50);

    delay(5000);
}
