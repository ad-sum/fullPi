#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H 
#include <stdbool.h>
#include <avr/io.h>

#define CONCATENATE(A,B) A##B
#define DDR(letter) CONCATENATE(DDR,letter)
#define PORT(letter) CONCATENATE(PORT,letter)
#define PIN(letter) CONCATENATE(PIN,letter)
#define PIN_B B
#define SELECT_IO_RS_PORT D
#define SELECT_IO_RW_PORT B
#define SELECT_IO_E_PORT D
#define SELECT_IO_RS 2
#define SELECT_IO_RW 0
#define SELECT_IO_E 4
#define SELECT_IO_RS_PORT D
#define SELECT_IO_RW_PORT B
#define SELECT_IO_DATA_PORT_B B
#define SELECT_IO_DATA_PORT_D D
#define DB4_PORT B
#define DB4_LOC 1
#define DB5_PORT B
#define DB5_LOC 4
#define DB6_PORT B
#define DB6_LOC 5
#define DB7_PORT D
#define DB7_LOC 7

void init_lcd_display();
bool get_DB4_bit();
bool get_DB5_bit();
bool get_DB6_bit();
bool get_DB7_bit();
void busywait();
void configure_bus_as_input();
void output_command_to_LCD(uint8_t command);
void clear_RW_bit();
void clear_RS_bit();
void set_RS_bit();
void configure_bus_as_output();
void lcd_erase();
void put_char(unsigned char x);
void lcd_goto_xy(uint8_t row, uint8_t col);
void puts_str(unsigned char * str);

#endif
