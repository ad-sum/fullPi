#ifndef QT_SENSOR_DRIVER_H
#define QT_SENSOR_DRIVER_H
#include <avr/io.h>
#define CONCATENATE(A,B) A##B
#define PORT(letter) CONCATENATE(PORT,letter)
#define DDR(letter) CONCATENATE(DDR,letter)
#define PIN(letter) CONCATENATE(PIN,letter)

#define SENSOR_PORT C
#define SENSOR_CONFIGURE_AS_INPUT_MASK 0b11100000
#define SENSOR_CONFIGURE_AS_OUTPUT_MASK 0b00011111

#define SENSOR_0_BIT 0
#define SENSOR_1_BIT 1
#define SENSOR_2_BIT 2
#define SENSOR_3_BIT 3
#define SENSOR_4_BIT 4

void configure_sensors_as_input();
void configure_sensors_as_output();
int8_t read_sensor_value();

#endif
