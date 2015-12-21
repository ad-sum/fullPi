#include "buzzer_driver.h"
#include <util/delay.h>

void init_buzzer() {
	DDR(BUZZER_DIR_REG) |= (1 << DDR_ENABLE_BIT);
	TCCR1A |= (1 << BUZZER_TCCR1A_BIT0);
	TCCR1A |= (1 << BUZZER_TCCR1A_BIT1);
	TCCR1A |= (1 << BUZZER_TCCR1A_BIT2);
	TCCR1B |= (1 << BUZZER_TCCR1B_BIT1);
}
void play_freq(uint16_t freq, uint8_t dur) {
	uint32_t top = (F_CPU) / (freq);
	TCCR1B |= (1 << BUZZER_TCCR1B_BIT2);
	OCR1A = top;
	OCR1B = (top >> 2);
	for (uint8_t i = 0; i < dur; i++) {
		_delay_ms(500);
	}
	TCCR1B &= ~(1 << 0);
}
