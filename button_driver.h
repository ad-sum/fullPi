#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H 
#include <avr/io.h>

#define CONCATENATE(A,B) A##B
#define DDR(letter) CONCATENATE(DDR,letter)
#define PORT(letter) CONCATENATE(PORT,letter)
#define PIN(letter) CONCATENATE(PIN,letter)

#define BUTTON_PORT B
#define LEFT_BUTTON 1
#define MIDDLE_BUTTON 4
#define RIGHT_BUTTON 5

void init_push_button_array();
char left_button_is_pressed();
char middle_button_is_pressed();
char right_button_is_pressed();
char is_pressed(char mask);

#endif
