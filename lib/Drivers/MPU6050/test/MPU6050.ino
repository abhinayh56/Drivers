#include "Arduino.h"
#include "../HAL/Common/I2C_bus/I2C_bus.h"
#include "../lib/Drivers/MPU6050/src/MPU6050.h"
#include <stdint.h>
#include "Wire.h"

I2C_bus<TwoWire> i2c_bus(&Wire);
MPU6050<I2C_bus<TwoWire>> imu(&i2c_bus, (uint8_t)MPU6050_INFO::ADDR::I2C_DEFAULT);

float SampleFrequency = 500.0, dt = 1.0/SampleFrequency;
unsigned long loop_timer = 1000000.0*dt, t;

int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

unsigned long t_n = 0;

void print_raw_sensor_data();
void wait();

void setup(){
  Serial.begin(115200);

  i2c_bus.init();
  i2c_bus.config(400000);
  imu.init();
  imu.config();
  
  Serial.println("---------------------------");
  Serial.println("Initializing test!");

  t = micros();
}

void loop(){
  t_n = micros();
  Serial.print((float)millis()/1000.0); Serial.print('\t');
  imu.get_data(&AcX, &AcY, &AcZ, &Tmp, &GyX, &GyY, &GyZ);
  print_raw_sensor_data();

  Serial.print(1000000.0/double(micros()-t_n)); Serial.print("\t");
  wait();
  Serial.println(1000000.0/double(micros()-t_n));
}

void print_raw_sensor_data()
{
  Serial.print(AcX); Serial.print('\t');
  Serial.print(AcY); Serial.print('\t');
  Serial.print(AcZ); Serial.print('\t');
  Serial.print(Tmp); Serial.print('\t');
  Serial.print(GyX); Serial.print('\t');
  Serial.print(GyY); Serial.print('\t');
  Serial.print(GyZ); Serial.print('\t');
}

void wait(){
  while(micros()-t<loop_timer){}
  t = micros();
}
