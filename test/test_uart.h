#include <Arduino.h>
#include "../lib/HAL/Common/UART_bus/UART_bus.h"

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