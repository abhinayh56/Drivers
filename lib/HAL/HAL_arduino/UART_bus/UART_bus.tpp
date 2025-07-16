#include "../../Common/UART_bus/UART_bus.h"

template <typename T_UART_bus>
UART_bus<T_UART_bus>::UART_bus(T_UART_bus *bus_) : bus(bus_)
{
}

template <typename T_UART_bus>
UART_bus<T_UART_bus>::~UART_bus()
{
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::init()
{
}

template <typename T_UART_bus>
bool UART_bus<T_UART_bus>::config(UART_param::Param &param_)
{
    param.baud_rate = param_.baud_rate;
    param.data_bits = param_.data_bits;
    param.stop_bits = param_.stop_bits;
    param.parity = param_.parity;
    param.flow_control = param_.flow_control;
    param.mode = param_.mode;

    bus->begin(param.baud_rate);

    return true;
}

template <typename T_UART_bus>
int32_t UART_bus<T_UART_bus>::available()
{
    return bus->available();
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::flush()
{
    bus->clear();
}

template <typename T_UART_bus>
uint8_t UART_bus<T_UART_bus>::receive_data()
{
    return bus->read();
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::receive_data(uint8_t *buffer, size_t length)
{
    bus->readBytes(buffer, length);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::send_data(uint8_t value)
{
    bus->write(value);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::send_data(const uint8_t *buffer, size_t length)
{
    bus->write(buffer, length);
}
template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(int8_t data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(uint8_t data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(uint16_t data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(int16_t data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(uint32_t data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(int32_t data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(uint64_t data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(int64_t data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(float data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(double data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(int data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(unsigned int data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(const String &data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(char data)
{
    bus->print(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(uint8_t data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(int8_t data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(uint16_t data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(int16_t data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(uint32_t data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(int32_t data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(uint64_t data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(int64_t data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(float data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(double data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(int data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(unsigned int data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(const String &data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(char data)
{
    bus->println(data);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(unsigned char data, int base)
{
    bus->print(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(int data, int base)
{
    bus->print(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(unsigned int data, int base)
{
    bus->print(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(long data, int base)
{
    bus->print(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(unsigned long data, int base)
{
    bus->print(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(int64_t data, int base)
{
    bus->print(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::print(uint64_t data, int base)
{
    bus->print(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(unsigned char data, int base)
{
    bus->println(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(int data, int base)
{
    bus->println(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(unsigned int data, int base)
{
    bus->println(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(long data, int base)
{
    bus->println(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(unsigned long data, int base)
{
    bus->println(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(int64_t data, int base)
{
    bus->println(data, base);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println(uint64_t data, int base)
{
    bus->println(data, base);
}
