F_CPU = 20000000
MCU = atmega328p
CCOPTS= -g -Wall -Os -std=c99

default: test

all: program

button_driver.o: button_driver.c button_driver.h
	avr-gcc -c $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) button_driver.c -o button_driver.o

lcd_driver.o: lcd_driver.c lcd_driver.h
	avr-gcc -c $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) lcd_driver.c -o lcd_driver.o

motor_driver_pwm.o: motor_driver_pwm.c motor_driver_pwm.h
	avr-gcc -c $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) motor_driver_pwm.c -o motor_driver_pwm.o

qt_sensor_driver.o: qt_sensor_driver.c qt_sensor_driver.h
	avr-gcc -c $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) qt_sensor_driver.c -o qt_sensor_driver.o
	
buzzer_driver.o: buzzer_driver.c buzzer_driver.h
	avr-gcc -c $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) buzzer_driver.c -o buzzer_driver.o

test: test.c lcd_driver.o button_driver.o motor_driver_pwm.o qt_sensor_driver.o buzzer_driver.o
	avr-gcc $(CCOPTS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -o test -g test.c lcd_driver.o button_driver.o motor_driver_pwm.o qt_sensor_driver.o buzzer_driver.o

test.hex: test
	avr-strip test
	avr-objcopy -R .eeprom -O ihex test test.hex

program: test.hex
	avrdude -p m328p -c avrisp2 -P /dev/ttyACM0 -U flash:w:test.hex

clean:
	rm test test.hex lcd_driver.o button_driver.o motor_driver_pwm.o qt_sensor_driver.o buzzer_driver.o

