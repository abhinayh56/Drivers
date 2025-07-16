#include "../../Common/I2C_bus.h"

template <typename T_I2C_bus>
I2C_bus<T_I2C_bus>::I2C_bus(T_I2C_bus *bus) : bus(bus)
{
}

template <typename T_I2C_bus>
void I2C_bus<T_I2C_bus>::init()
{
	bus->begin();
}

template <typename T_I2C_bus>
void I2C_bus<T_I2C_bus>::config(uint32_t freq)
{
	bus->setClock(freq);
}

template <typename T_I2C_bus>
uint8_t I2C_bus<T_I2C_bus>::receive_data(uint8_t address)
{
	bus->beginTransmission(address);
	bus->requestFrom((uint8_t)address, (uint8_t)1);
	while (bus->available() < 1)
		;
	uint8_t value = bus->read();
	bus->endTransmission();
	return value;
}

template <typename T_I2C_bus>
void I2C_bus<T_I2C_bus>::receive_data(uint8_t address, uint8_t *buffer, uint8_t length)
{
	bus->beginTransmission(address);
	bus->requestFrom((uint8_t)address, (uint8_t)length);
	while (bus->available() < length)
		;
	for (uint8_t i = 0; i < length; i++)
	{
		buffer[i] = bus->read();
	}
	bus->endTransmission(address);
}

template <typename T_I2C_bus>
uint8_t I2C_bus<T_I2C_bus>::receive_data(uint8_t address, uint8_t reg)
{
	bus->beginTransmission(address);
	bus->write(reg);
	bus->endTransmission();
	bus->requestFrom((uint8_t)address, (uint8_t)1);
	while (bus->available() < 1)
		;
	return bus->read();
}

template <typename T_I2C_bus>
void I2C_bus<T_I2C_bus>::receive_data(uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t length)
{
	bus->beginTransmission(address);
	bus->write(reg);
	bus->endTransmission();
	bus->requestFrom((uint8_t)address, (uint8_t)length);
	while (bus->available() < length)
		;
	for (uint8_t i = 0; i < length; i++)
	{
		buffer[i] = bus->read();
	}
}

template <typename T_I2C_bus>
void I2C_bus<T_I2C_bus>::send_data(uint8_t address, uint8_t value)
{
	bus->beginTransmission(address);
	bus->write(value);
	bus->endTransmission();
}

template <typename T_I2C_bus>
void I2C_bus<T_I2C_bus>::send_data(uint8_t address, uint8_t *values, uint8_t length)
{
	bus->beginTransmission(address);
	for (uint8_t i = 0; i < length; i++)
	{
		bus->write(values[i]);
	}
	bus->endTransmission();
}

template <typename T_I2C_bus>
void I2C_bus<T_I2C_bus>::send_data(uint8_t address, uint8_t reg, uint8_t value)
{
	bus->beginTransmission(address);
	bus->write(reg);
	bus->write(value);
	bus->endTransmission();
}

template <typename T_I2C_bus>
void I2C_bus<T_I2C_bus>::send_data(uint8_t address, uint8_t reg, uint8_t *values, uint8_t length)
{
	bus->beginTransmission(address);
	bus->write(reg);
	for (uint8_t i = 0; i < length; i++)
	{
		bus->write(values[i]);
	}
	bus->endTransmission();
}
