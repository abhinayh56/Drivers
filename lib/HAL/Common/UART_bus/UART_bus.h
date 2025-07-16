#ifndef UART_BUS_H
#define UART_BUS_H

#include <stdint.h>
#include <stddef.h>
#include <WString.h>

namespace UART_param
{
    enum Baud_rate : uint32_t
    {
        BPS_9600 = 9600,
        BPS_38400 = 38400,
        BPS_57600 = 57600,
        BPS_115200 = 115200
    };

    enum Data_bits : uint8_t
    {
        BITS_8 = 8,
        BITS_9 = 9
    };

    enum Stop_bits : uint8_t
    {
        BITS_1 = 1,
        BITS_1_5 = 15,
        BITS_2 = 2
    };

    enum Parity : uint8_t
    {
        NONE = 0,
        EVEN = 1,
        ODD = 2
    };

    enum Flow_control : uint8_t
    {
        NO_FLOW_CONTROL = 0,
        HARDWARE = 1,
        SOFTWARE = 2
    };

    enum Mode : uint8_t
    {
        TRANSMIT = 0,
        RECEIVE = 1,
        TRANSMIT_RECEIVE = 2
    };

    struct Param
    {
        uint32_t baud_rate = 9600;
        uint8_t data_bits = UART_param::Data_bits::BITS_8;
        uint8_t stop_bits = UART_param::Stop_bits::BITS_1;
        uint8_t parity = UART_param::Parity::NONE;
        uint8_t flow_control = UART_param::Flow_control::NO_FLOW_CONTROL;
        uint8_t mode = UART_param::Mode::TRANSMIT_RECEIVE;
    };
}

template <typename T_UART_bus>
class UART_bus
{
public:
    UART_bus(T_UART_bus *bus_);
    ~UART_bus();

    void init();
    bool config(UART_param::Param &param_);

    int32_t available();
    void flush();

    uint8_t receive_data();
    void    receive_data(uint8_t *buffer, size_t length);
    void    send_data(uint8_t value);
    void    send_data(const uint8_t *buffer, size_t length);

    void    print(uint8_t data);
    void    print(int8_t data);
    void    print(uint16_t data);
    void    print(int16_t data);
    void    print(uint32_t data);
    void    print(int32_t data);
    void    print(uint64_t data);
    void    print(int64_t data);
    void    print(float data);
    void    print(double data);
    void    print(int data);
    void    print(unsigned int data);
    void    print(const String &data);
    void    print(char data);

    void    println(uint8_t data);
    void    println(int8_t data);
    void    println(uint16_t data);
    void    println(int16_t data);
    void    println(uint32_t data);
    void    println(int32_t data);
    void    println(uint64_t data);
    void    println(int64_t data);
    void    println(float data);
    void    println(double data);
    void    println(int data);
    void    println(unsigned int data);
    void    println(const String &data);
    void    println(char data);
    
    void    print(unsigned char data, int base);
    void    print(int data, int base);
    void    print(unsigned int data, int base);
    void    print(long data, int base);
    void    print(unsigned long data, int base);
    void    print(int64_t data, int base);
    void    print(uint64_t data, int base);

    void    println(unsigned char data, int base);
    void    println(int data, int base);
    void    println(unsigned int data, int base);
    void    println(long data, int base);
    void    println(unsigned long data, int base);
    void    println(int64_t data, int base);
    void    println(uint64_t data, int base);

private:
    T_UART_bus *bus;

    UART_param::Param param = {UART_param::Baud_rate::BPS_9600,
                               UART_param::Data_bits::BITS_8,
                               UART_param::Stop_bits::BITS_1,
                               UART_param::Parity::NONE,
                               UART_param::Flow_control::NO_FLOW_CONTROL,
                               UART_param::Mode::TRANSMIT_RECEIVE};
};

#include "UART_platform_select.h"

#endif // UART_BUS_H
