#ifndef I2C_BUS_H
#define I2C_BUS_H

#include "Arduino.h"
#include <Wire.h>
#include <stdint.h>

template <typename T_I2C_bus>
class I2C_bus {
	public:
		I2C_bus(T_I2C_bus* bus);
		void init();
		void config(uint32_t freq);
		uint8_t read_register(uint8_t address, uint8_t reg);
		void read_registers(uint8_t address, uint8_t reg, uint8_t* buffer, uint8_t length);
		void write_register(uint8_t address, uint8_t reg, uint8_t value);
		void write_registers(uint8_t address, uint8_t reg, uint8_t* values, uint8_t length);
		void send_data(uint8_t address, uint8_t value);
		void send_data(uint8_t address, uint8_t* buffer, uint8_t length);
		uint8_t receive_data(uint8_t address);
		uint8_t receive_data(uint8_t address, uint8_t* buffer, uint8_t length);

	private:
		T_I2C_bus* bus;
};

#endif