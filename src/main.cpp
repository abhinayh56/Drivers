#include "Arduino.h"
#include "../Drivers/I2C_bus/src/I2C_bus.h"
#include "../Drivers/MS5611/src/MS5611.h"
#include "Wire.h"
#include <stdint.h>

I2C_bus<TwoWire> i2c_bus(&Wire);
MS5611<I2C_bus<TwoWire>> bar(&i2c_bus, (uint8_t)MS5611_INFO::ADDR::I2C_DEFAULT);

float SampleFrequency = 500.0, dt = 1.0/SampleFrequency;
unsigned long loop_timer = 1000000.0*dt, t;

double press = 0;
double temp = 0;

unsigned long t_n = 0;

void wait();

void setup()
{
	Serial.begin(115200);

	i2c_bus.init();
	i2c_bus.config(400000);
	bar.init();
	delay(5);
	bar.config(4096, 4096, (uint16_t)loop_timer, 3);

	Serial.println("---------------------------");
	Serial.println("Initializing test!");

	t = micros();
}

void loop()
{
	t_n = micros();
	Serial.print((float)millis() / 1000.0);
	Serial.print('\t');
	bar.get_data(&press, &temp);

	Serial.print(press);
	Serial.print('\t');
	Serial.print(temp);
	Serial.print('\t');

	Serial.print(1000000.0 / double(micros() - t_n));
	Serial.print("\t");
	wait();
	Serial.println(1000000.0 / double(micros() - t_n));
}

void wait()
{
	while (micros() - t < loop_timer)
	{
	}
	t = micros();
}
