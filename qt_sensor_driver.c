#include "qt_sensor_driver.h"
void configure_sensors_as_input()
{
	DDR(SENSOR_PORT) &= SENSOR_CONFIGURE_AS_INPUT_MASK;
	PORT(SENSOR_PORT) |= ((1 << SENSOR_0_BIT) | (1 << SENSOR_1_BIT) | (1 << SENSOR_2_BIT) | (1 << SENSOR_3_BIT) | (1 << SENSOR_4_BIT));
}
void configure_sensors_as_output()
{
	DDR(SENSOR_PORT) |= SENSOR_CONFIGURE_AS_OUTPUT_MASK;
}
int8_t read_sensor_value()
{
	int8_t sensor_value = 0;
	uint8_t i = 0;
	if ((PIN(SENSOR_PORT) & (1 << SENSOR_0_BIT)) != 0)
	{
		sensor_value = sensor_value - 127;
		i++;
	}
	if((PIN(SENSOR_PORT) & (1 << SENSOR_1_BIT)) != 0)
	{
                sensor_value = sensor_value - 64;
                i++;
	}
	if((PIN(SENSOR_PORT) & (1 << SENSOR_2_BIT)) != 0)
        {
                sensor_value = sensor_value - 0;
                i++;
        }
        if((PIN(SENSOR_PORT) & (1 << SENSOR_3_BIT)) != 0)
        {
                sensor_value = sensor_value + 64;
                i++;
        }
        if((PIN(SENSOR_PORT) & (1 << SENSOR_4_BIT)) != 0)
        {
                sensor_value = sensor_value + 127;
                i++;
        }
	return (sensor_value/i);
}
