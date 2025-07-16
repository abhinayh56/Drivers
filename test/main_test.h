// #define TEST_MPU6050
// #define TEST_HMC5883
// #define TEST_MS5611

#ifdef TEST_MPU6050
#include "../lib/Drivers/MPU6050/test/MPU6050.ino"

#elif defined(TEST_HMC5883)
#include "../lib/Drivers/HMC5883/test/HMC5883.ino"

#elif defined(TEST_MS5611)
#include "../lib/Drivers/MS5611/test/MS5611.ino"

#else
#include <Arduino.h>

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
