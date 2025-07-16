#include "Arduino.h"
#include "../HAL/Common/I2C_bus/I2C_bus.h"
#include "../lib/Drivers/HMC5883/src/HMC5883.h"
#include <stdint.h>
#include "Wire.h"

I2C_bus<TwoWire> i2c_bus(&Wire);
HMC5883<I2C_bus<TwoWire>> mag(&i2c_bus, (uint8_t)HMC5883_INFO::ADDR::I2C_DEFAULT);

float SampleFrequency = 500.0, dt = 1.0 / SampleFrequency;
unsigned long loop_timer = 1000000.0 * dt, t;

int16_t MgX, MgY, MgZ;

unsigned long t_n = 0;

void print_raw_sensor_data();
void wait();

void setup()
{
  Serial.begin(115200);

  i2c_bus.init();
  i2c_bus.config(400000);
  mag.init();
  mag.config();

  Serial.println("---------------------------");
  Serial.println("Initializing test!");

  t = micros();
}

void loop()
{
  t_n = micros();
  Serial.print((float)millis() / 1000.0);
  Serial.print('\t');
  mag.get_data(&MgX, &MgY, &MgZ);
  print_raw_sensor_data();

  Serial.print(1000000.0 / double(micros() - t_n));
  Serial.print("\t");
  wait();
  Serial.println(1000000.0 / double(micros() - t_n));
}

void print_raw_sensor_data()
{
  Serial.print(MgX);
  Serial.print('\t');
  Serial.print(MgY);
  Serial.print('\t');
  Serial.print(MgZ);
  Serial.print('\t');
}

void wait()
{
  while (micros() - t < loop_timer)
  {
  }
  t = micros();
}
