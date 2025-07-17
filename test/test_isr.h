#include <Arduino.h>
#include "../lib/HAL/Common/ISR_channel/ISR_channel.h"

uint8_t isr_pin_1 = 5;
ISR_channel<uint8_t> isr_channel_1(&isr_pin_1);

volatile int count = 0;
int count_pre = 0;

void isr_fun_1();

void setup()
{
    Serial.begin(115200);
    isr_channel_1.config(isr_pin_1, isr_fun_1, ISR_channel_param::Trigger::EDGE_RISING);
    delay(5000);
    Serial.println(count);
}

void loop()
{
    if (count != count_pre)
    {
        Serial.println(count);
        count_pre = count;
    }
}

void isr_fun_1()
{
    count++;
}
