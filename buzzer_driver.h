#ifndef BUZZER_DRIVER_H
#define BUZZER_DRIVER_H
#include <avr/io.h>

#define CONCATENATE(A,B) A##B
#define PORT(letter) CONCATENATE(PORT,letter)
#define DDR(letter) CONCATENATE(DDR,letter)
#define PIN(letter) CONCATENATE(PIN,letter)
#define TCCR(symbol) CONCATENATE(TCCR,symbol)
#define OCR(symbol) CONCATENATE(OCR,symbol)

#define BUZZER_DIR_REG B
#define BUZZER_TCCR1A 1A
#define BUZZER_TCCR1B 1B

#define DDR_ENABLE_BIT 2
#define BUZZER_TCCR1A_BIT0 0
#define BUZZER_TCCR1A_BIT1 4
#define BUZZER_TCCR1A_BIT2 5
#define BUZZER_TCCR1B_BIT1 4
#define BUZZER_TCCR1B_BIT2 0

void play_freq(uint16_t freq, uint8_t dur);
void init_buzzer();

#endif
