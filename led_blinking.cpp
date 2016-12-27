// Sample LED blinking program

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "libgpiopi.hpp"

int main(void)
{
	// Blink LED 6 times
	unsigned int sleeptime = 170; //milliseconds
	// Setup pin 17
	rpi_pin led_p17(17);
	led_p17.pin_export();
	std::cout << "Pin exported" << std::endl;
	led_p17.output();
	
	unsigned int i = 0;
	while (i<6)
	{
		usleep(sleeptime * 1000); //microseconds
		led_p17.set_value("1");
		std::usleep(sleeptime * 1000);
		led_p17.set_value("0");
		i++;
	}
	
	// cleanup
	led_p17.pin_unexport();
	return 0;
}