#include "motor_driver_pwm.h"
#include <avr/io.h>
void configure_left_motor()
{
 DDR(LEFT_MOTOR_A_PORT) |= (1<<LEFT_MOTOR_A);
 DDR(LEFT_MOTOR_B_PORT) |= (1<<LEFT_MOTOR_B);
}
void set_left_motor_speed(uint8_t speed)
{
 OCR(LEFT_MOTOR_OCR_0A)=speed;
 OCR(LEFT_MOTOR_OCR_0B)=speed;
}
void shift_left_motor_forward()
{
 TCCR(LEFT_MOTOR_TCCR_0B)|= (1<<CS00);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<WGM00);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<WGM01);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<COM0B0);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<COM0B1);
}
void shift_left_motor_reverse()
{
 TCCR(LEFT_MOTOR_TCCR_0B)|= (1<<CS00);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<WGM00);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<WGM01);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<COM0A0);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<COM0A1);
}
void shift_left_motor_brake()
{
 TCCR(LEFT_MOTOR_TCCR_0B)|= (1<<CS00);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<WGM00);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<WGM01);
 TCCR(LEFT_MOTOR_TCCR_0A)&= ~(1<<COM0A0);
 TCCR(LEFT_MOTOR_TCCR_0A)&= ~(1<<COM0A1);
 TCCR(LEFT_MOTOR_TCCR_0A)&= ~(1<<COM0B0);
 TCCR(LEFT_MOTOR_TCCR_0A)&= ~(1<<COM0B1);
 PORT(LEFT_MOTOR_A_PORT) |= (1<<LEFT_MOTOR_A);
 PORT(LEFT_MOTOR_B_PORT) |= (1<<LEFT_MOTOR_B);
}
void shift_left_motor_coast()
{
 TCCR(LEFT_MOTOR_TCCR_0B)|= (1<<CS00);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<WGM00);
 TCCR(LEFT_MOTOR_TCCR_0A)|= (1<<WGM01);
 TCCR(LEFT_MOTOR_TCCR_0A)&= ~(1<<COM0A0);
 TCCR(LEFT_MOTOR_TCCR_0A)&= ~(1<<COM0A1);
 TCCR(LEFT_MOTOR_TCCR_0A)&= ~(1<<COM0B0);
 TCCR(LEFT_MOTOR_TCCR_0A)&= ~(1<<COM0B1);
 PORT(RIGHT_MOTOR_A_PORT) &= ~(1<<LEFT_MOTOR_A);
 PORT(RIGHT_MOTOR_B_PORT) &= ~(1<<LEFT_MOTOR_B);
}
uint8_t get_left_motor_speed()
{
 return OCR0A;
}
void configure_right_motor()
{
 DDR(RIGHT_MOTOR_A_PORT) |= (1<<RIGHT_MOTOR_A);
 DDR(RIGHT_MOTOR_B_PORT) |= (1<<RIGHT_MOTOR_B);
}
void set_right_motor_speed(uint8_t speed)
{
 OCR(RIGHT_MOTOR_OCR_2A)=speed;
 OCR(RIGHT_MOTOR_OCR_2B)=speed;
}
void shift_right_motor_forward()
{
 TCCR(RIGHT_MOTOR_TCCR_2B)|= (1<<CS00);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<WGM00);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<WGM01);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<COM0B0);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<COM0B1);
}
void shift_right_motor_reverse()
{
 TCCR(RIGHT_MOTOR_TCCR_2B)|= (1<<CS00);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<WGM00);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<WGM01);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<COM0A0);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<COM0A1);
}
void shift_right_motor_brake()
{
 TCCR(RIGHT_MOTOR_TCCR_2B)|= (1<<CS00);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<WGM00);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<WGM01);
 TCCR(RIGHT_MOTOR_TCCR_2A)&= ~(1<<COM0A0);
 TCCR(RIGHT_MOTOR_TCCR_2A)&= ~(1<<COM0A1);
 TCCR(RIGHT_MOTOR_TCCR_2A)&= ~(1<<COM0B0);
 TCCR(RIGHT_MOTOR_TCCR_2A)&= ~(1<<COM0B1);
 PORT(RIGHT_MOTOR_A_PORT) |= (1<<RIGHT_MOTOR_A);
 PORT(RIGHT_MOTOR_B_PORT) |= (1<<RIGHT_MOTOR_B);
}
void shift_right_motor_coast()
{
 TCCR(RIGHT_MOTOR_TCCR_2B)|= (1<<CS00);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<WGM00);
 TCCR(RIGHT_MOTOR_TCCR_2A)|= (1<<WGM01);
 TCCR(RIGHT_MOTOR_TCCR_2A)&= ~(1<<COM0A0);
 TCCR(RIGHT_MOTOR_TCCR_2A)&= ~(1<<COM0A1);
 TCCR(RIGHT_MOTOR_TCCR_2A)&= ~(1<<COM0B0);
 TCCR(RIGHT_MOTOR_TCCR_2A)&= ~(1<<COM0B1);
 PORT(RIGHT_MOTOR_A_PORT) &= ~(1<<RIGHT_MOTOR_A);
 PORT(RIGHT_MOTOR_B_PORT) &= ~(1<<RIGHT_MOTOR_B);
}
uint8_t get_right_motor_speed()
{
 return OCR2A;
}
