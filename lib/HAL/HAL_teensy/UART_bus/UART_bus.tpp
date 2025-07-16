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
void UART_bus<T_UART_bus>::print()
{
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::println()
{
}