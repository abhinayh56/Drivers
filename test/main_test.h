// #define TEST_MPU6050
// #define TEST_HMC5883
// #define TEST_MS5611
#define TEST_UART_0

#ifdef TEST_MPU6050
#include "../lib/Drivers/MPU6050/test/MPU6050.ino"

#elif defined(TEST_HMC5883)
#include "../lib/Drivers/HMC5883/test/HMC5883.ino"

#elif defined(TEST_MS5611)
#include "../lib/Drivers/MS5611/test/MS5611.ino"

#elif defined(TEST_UART_0)
#include "../lib/HAL/Common/UART_bus/UART_bus.h"
#include <Arduino.h>

UART_bus<usb_serial_class> uart_0(&Serial);

void setup()
{
    UART_param::Param uart_0_param{115200,
                                   UART_param::Data_bits::BITS_8,
                                   UART_param::Stop_bits::BITS_1,
                                   UART_param::Parity::NONE,
                                   UART_param::Flow_control::NO_FLOW_CONTROL,
                                   UART_param::Mode::TRANSMIT_RECEIVE};

    uart_0.config(uart_0_param);

    delay(5000);
}

void loop()
{
    uart_0.print("This is single line 1");
    uart_0.println("This is single line 2");
    uart_0.print(56);
    delay(1000);
}

#else
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

#endif
