#include "button_driver.h"
#include <avr/io.h>

void init_push_button_array() {
	DDR(BUTTON_PORT) &= ~(1 << RIGHT_BUTTON);
	DDR(BUTTON_PORT) &= ~(1 << MIDDLE_BUTTON);
	DDR(BUTTON_PORT) &= ~(1 << LEFT_BUTTON);
}
char left_button_is_pressed() {
	if ((PIN(BUTTON_PORT) & (1 << LEFT_BUTTON)) == (1 << LEFT_BUTTON))
		return 0;
	else
		return 1;
}
char middle_button_is_pressed() {
	if ((PIN(BUTTON_PORT) & (1 << MIDDLE_BUTTON)) == (1 << MIDDLE_BUTTON))
		return 0;
	else
		return 1;
}
char right_button_is_pressed() {
	if ((PIN(BUTTON_PORT) & (1 << RIGHT_BUTTON)) == (1 << RIGHT_BUTTON))
		return 0;
	else
		return 1;
}

