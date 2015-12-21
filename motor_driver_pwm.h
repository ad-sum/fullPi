#include <avr/io.h>
#ifndef MOTOR_DRIVER_PWM_H
#define MOTOR_DRIVER_PWM_H
#define CONCATENATE(A,B) A##B
#define DDR(letter) CONCATENATE(DDR,letter)
#define PORT(letter) CONCATENATE(PORT,letter)
#define PIN(letter)  CONCATENATE(PIN,letter)
#define TCCR(symbol) CONCATENATE(TCCR,symbol)
#define OCR(symbol) CONCATENATE(OCR,symbol)//2 symbols. Eclipse views as bug
#define LEFT_MOTOR_A_PORT D
#define LEFT_MOTOR_B_PORT D
#define RIGHT_MOTOR_A_PORT D
#define RIGHT_MOTOR_B_PORT B
#define LEFT_MOTOR_A 6
#define LEFT_MOTOR_B 5 
#define RIGHT_MOTOR_A 3
#define RIGHT_MOTOR_B 3
#define LEFT_MOTOR_OCR_0A 0A
#define LEFT_MOTOR_OCR_0B 0B
#define RIGHT_MOTOR_OCR_2A 2A
#define RIGHT_MOTOR_OCR_2B 2B
#define LEFT_MOTOR_TCCR_0B 0B
#define LEFT_MOTOR_TCCR_0A 0A
#define RIGHT_MOTOR_TCCR_2B 2B
#define RIGHT_MOTOR_TCCR_2A 2A
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM00 0
#define WGM01 1
#define WGM02 3
#define WGM20 0
#define WGM21 1
#define WGM22 3
#define COM0A1 7
#define COM0A0 6
#define COM0B1 5
#define COM0B0 4
#define COM2A1 7
#define COM2A0 6
#define COM2B1 5
#define COM2B0 4
void configure_left_motor();
void configure_right_motor();
void set_left_motor_speed(uint8_t speed);
void shift_left_motor_forward();
void shift_left_motor_reverse();
void shift_left_motor_brake();
void shift_left_motor_coast();
uint8_t get_left_motor_speed();
void set_right_motor_speed(uint8_t speed);
void shift_right_motor_forward();
void shift_right_motor_reverse();
void shift_right_motor_brake();
void shift_right_motor_coast();
uint8_t get_right_motor_speed();
#endif
