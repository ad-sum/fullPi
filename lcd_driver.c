#include "lcd_driver.h"
#include <util/delay.h>
#include <avr/io.h>

static void set_DB4_bit() {
	PORT(DB4_PORT) |= (1 << DB4_LOC);
}
static void set_DB5_bit() {
	PORT(DB5_PORT) |= (1 << DB5_LOC);
}
static void set_DB6_bit() {
	PORT(DB6_PORT) |= (1 << DB6_LOC);
}
static void set_DB7_bit() {
	PORT(DB7_PORT) |= (1 << DB7_LOC);
}
static void clear_DB4_bit() {
	PORT(DB4_PORT) &= ~(1 << DB4_LOC);
}
static void clear_DB5_bit() {
	PORT(DB5_PORT) &= ~(1 << DB5_LOC);
}
static void clear_DB6_bit() {
	PORT(DB6_PORT) &= ~(1 << DB6_LOC);
}
static void clear_DB7_bit() {
	PORT(DB7_PORT) &= ~(1 << DB7_LOC);
}
void clear_RW_bit() {
	PORT(SELECT_IO_RW_PORT) &= ~(1 << SELECT_IO_RW);
}
void clear_RS_bit() {
	PORT(SELECT_IO_RS_PORT) &= ~(1 << SELECT_IO_RS);
}
void set_RS_bit() {
	PORT(SELECT_IO_RS_PORT) |= (1 << SELECT_IO_RS);
}
void configure_bus_as_output() {
	DDR(SELECT_IO_DATA_PORT_B) |= (1 << DB4_LOC);
	DDR(SELECT_IO_DATA_PORT_B) |= (1 << DB5_LOC);
	DDR(SELECT_IO_DATA_PORT_B) |= (1 << DB6_LOC);
	DDR(SELECT_IO_DATA_PORT_D) |= (1 << DB7_LOC);
}
void configure_bus_as_input() {
	DDR(SELECT_IO_DATA_PORT_B) &= ~(1 << DB4_LOC);
	DDR(SELECT_IO_DATA_PORT_B) &= ~(1 << DB5_LOC);
	DDR(SELECT_IO_DATA_PORT_B) &= ~(1 << DB6_LOC);
	DDR(SELECT_IO_DATA_PORT_D) &= ~(1 << DB7_LOC);
}
bool get_DB4_bit() {
	return PIN(SELECT_IO_DATA_PORT_B) & (1 << DB4_LOC);
}
bool get_DB5_bit() {
	return PIN(SELECT_IO_DATA_PORT_B) & (1 << DB5_LOC);
}
bool get_DB6_bit() {
	return PIN(SELECT_IO_DATA_PORT_B) & (1 << DB6_LOC);
}
bool get_DB7_bit() {
	return PIN(SELECT_IO_DATA_PORT_D) & (1 << DB7_LOC);
}
static uint8_t input_nibble_from_DB() {
	uint8_t data = 0;
	if (get_DB4_bit()) {
		data |= (1 << 0);
	}
	if (get_DB5_bit()) {
		data |= (1 << 1);
	}
	if (get_DB6_bit()) {
		data |= (1 << 2);
	}
	if (get_DB7_bit()) {
		data |= (1 << 3);
	}
	return data;
}
static uint8_t pulse_E() {
	uint8_t data;
	PORT(SELECT_IO_E_PORT) |= (1 << SELECT_IO_E);
	_delay_ms(1);
	data = input_nibble_from_DB();
	PORT(SELECT_IO_E_PORT) &= ~(1 << SELECT_IO_E);
	return data;
}
#define BUSY_FLAG (1<<7)
void busywait() {
	uint8_t data;
	configure_bus_as_input();
	PORT(SELECT_IO_RS_PORT) &= ~(1 << SELECT_IO_RS);
	PORT(SELECT_IO_RW_PORT) |= (1 << SELECT_IO_RW);
	do {
		data = pulse_E();
		pulse_E();
	} while ((data) & ((1 << 3) == 1));
}
static void nibble_out(uint8_t data) {
	if (data & (1 << 0)) {
		set_DB4_bit();
	} else {
		clear_DB4_bit();
	}
	if (data & (1 << 1)) {
		set_DB5_bit();
	} else {
		clear_DB5_bit();
	}
	if (data & (1 << 2)) {
		set_DB6_bit();
	} else {
		clear_DB6_bit();
	}
	if (data & (1 << 3)) {
		set_DB7_bit();
	} else {
		clear_DB7_bit();
	}
	pulse_E();
}
static void output_byte_LCD(uint8_t data, bool rs) {
	busywait();
	clear_RW_bit();
	if ((rs == 0)) {
		clear_RS_bit();
	} else {
		set_RS_bit();
	}
	configure_bus_as_output();
	nibble_out(data >> 4);
	nibble_out(data);
	configure_bus_as_input();
	set_DB4_bit();
	set_DB5_bit();
	set_DB6_bit();
	set_DB7_bit();
}
void output_command_to_LCD(uint8_t command) {
	output_byte_LCD(command, 0);
}
void init_lcd_display() {
	PORT(SELECT_IO_RS_PORT) &= ~(1 << SELECT_IO_RS);
	PORT(SELECT_IO_RW_PORT) &= ~(1 << SELECT_IO_RW);
	PORT(SELECT_IO_E_PORT) &= ~(1 << SELECT_IO_E);
	DDR(SELECT_IO_RS_PORT) |= (1 << SELECT_IO_RS);
	DDR(SELECT_IO_RW_PORT) |= (1 << SELECT_IO_RW);
	DDR(SELECT_IO_E_PORT) |= (1 << SELECT_IO_E);
	configure_bus_as_output();
	_delay_ms(15);
	nibble_out(0x3);
	_delay_ms(6);
	nibble_out(0x3);
	_delay_ms(2);
	nibble_out(0x3);
	_delay_ms(2);
	nibble_out(0x2);
	busywait();
	output_command_to_LCD(0x28);
	output_command_to_LCD(0x0D);
	output_command_to_LCD(0x01);
	output_command_to_LCD(0x06);
}
void lcd_erase() {
	output_byte_LCD(0x01, 0);
}
void put_char(unsigned char x) {
	output_byte_LCD(x, 1);
}
void lcd_goto_xy(uint8_t row, uint8_t col) {
	output_byte_LCD(0x7f + col + ((row - 1) * 0x40), 0);
}
//Poorly designed::Requires strlen > 8
void puts_str(unsigned char * str) {
	lcd_erase();
	uint8_t i;
	lcd_goto_xy(1, 1);
	for (i = 1; i++; i < 9) {
		if (str[i - 2] == 0)
			break;
		put_char(str[i - 2]);
	}
	lcd_goto_xy(2, 1);
	for (i = 9; i++; i < 17) {
		if (str[i - 2] == 0)
			break;
		put_char(str[i - 2]);
	}
}
