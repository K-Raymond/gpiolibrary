// Sample LED blinking program

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "libgpiopi.hpp"

using namespace std;

int main(void)
{
	// Blink LED 6 times
	unsigned int sleeptime = 500; //milliseconds
	// Setup pin 17
	rpi_pin led(17);
  cout << "pin constructed" << endl;
	led.pin_export();
	cout << "Pin exported" << endl;
	led.output();
  cout << "pin set as output" << endl;
	
	unsigned int i = 0;
	while (i<6)
	{
    cout << "interation: " << i+1 << endl;
		usleep(sleeptime * 1000); //microseconds
		led.set_value("1");
		usleep(sleeptime * 1000);
		led.set_value("0");
		i++;
	}
	
	// cleanup
	led.pin_unexport();
	return 0;
}
