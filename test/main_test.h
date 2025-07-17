// #define TEST_MPU6050
// #define TEST_HMC5883
// #define TEST_MS5611
// #define TEST_UART_0
// #define TEST_PWM
#define TEST_ISR

// ------------------------------------------------
#ifdef TEST_MPU6050
#include "./test_mpu6050.h"

#elif defined(TEST_HMC5883)
#include "./test_hmc5883.h"

#elif defined(TEST_MS5611)
#include "./test_ms5611.h"

#elif defined(TEST_UART_0)
#include "./test_uart.h"

#elif defined(TEST_PWM)
#include "./test_pwm.h"

#elif defined(TEST_ISR)
#include "./test_isr.h"

#else
#include "./test_none.h"

#endif
