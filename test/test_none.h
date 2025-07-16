#include <Arduino.h>
#include "../lib/HAL/Common/UART_bus/UART_bus.h"

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.println("NO TEST SELECTED. SELECT ONE TEST");
    delay(1000);
}