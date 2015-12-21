#include "lcd_driver.h"
#include "button_driver.h"
#include "buzzer_driver.h"
#include "motor_driver_pwm.h"
#include "qt_sensor_driver.h"
#include <util/delay.h>

int main() {
	init_lcd_display();
	init_buzzer();
	init_push_button_array();
	unsigned char str[] = "fullPi  PROJECT";
	puts_str(str);

	while (1) {

		if (left_button_is_pressed()) {
			//E Major
			//E, F♯, G♯, A, B, C♯, D♯, E
			play_freq(412, 1);		//E1 =41.2 Hz
			play_freq(463, 1);		//F#
			play_freq(519, 1);		//G#
			play_freq(550, 1);		//A
			play_freq(617, 1);		//B
			play_freq(693, 1);		//C#
			play_freq(778, 1);		//D#
			play_freq(824, 1);		//E2
		}
		if (middle_button_is_pressed()) {
			while (1) {
				configure_left_motor();
				configure_right_motor();
				configure_sensors_as_input();
				int8_t direction = 0;
				uint8_t pwm_speedL = 40;
				uint8_t pwm_speedR = 40;

				shift_left_motor_forward();
				shift_right_motor_forward();
				set_left_motor_speed(pwm_speedL);
				set_right_motor_speed(pwm_speedR);

				_delay_ms(1);
				shift_left_motor_brake();
				shift_right_motor_brake();

				direction = read_sensor_value();

				if ((direction >= -63) && (direction < 15)) {
					pwm_speedL = 20;
					pwm_speedR = 30;
					shift_left_motor_forward();
					shift_right_motor_forward();
					set_left_motor_speed(pwm_speedL);
					set_right_motor_speed(pwm_speedR);
					//puts("left");
					_delay_ms(10);
					shift_left_motor_brake();
					shift_right_motor_brake();
				} else if (direction < -63) {
					pwm_speedL = 20;		//40;
					pwm_speedR = 40;		//60;
					shift_left_motor_forward();
					shift_right_motor_forward();
					set_left_motor_speed(pwm_speedL);
					set_right_motor_speed(pwm_speedR);

					_delay_ms(10);
					shift_left_motor_brake();
					shift_right_motor_brake();
				} else if ((direction > 15) && (direction <= 63)) {
					pwm_speedL = 30;
					pwm_speedR = 20;
					shift_left_motor_forward();
					shift_right_motor_forward();
					set_left_motor_speed(pwm_speedL);
					set_right_motor_speed(pwm_speedR);

					_delay_ms(10);
					shift_left_motor_brake();
					shift_right_motor_brake();
				} else if ((direction > 63)) {

					pwm_speedL = 40;		//60;
					pwm_speedR = 20;		//40;
					shift_left_motor_forward();
					shift_right_motor_forward();
					set_left_motor_speed(pwm_speedL);
					set_right_motor_speed(pwm_speedR);

					_delay_ms(10);
					shift_left_motor_brake();
					shift_right_motor_brake();
				}

			}
		}

	}
}
