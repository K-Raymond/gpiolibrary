// File: libgpiorpi.hpp

#ifndef rpi_pin_CLASS_H
#define rpi_pin_CLASS_H

#include <string>

/*
A basic library for controlling the gpio pins on a raspberry pi

Uses an intellegent interface to manage pins:
1. construct the pin
2. export the pin and then specify if the pin should be output or input
3. set the value of the output

ie,
rpi_pin led_p17(17);
led_p17.export();
led_p17.output();

if( condition ) set_value("1");

*/

class rpi_pin
{
	public:
	
	rpi_pin(); // Should never be run
	rpi_pin(int pin); //Create a gpio pin instance
	int pin_export(); //export the pin
	int pin_unexport(); //unexport the pin
	int input(); //Set pin as input
	int output(); //Set pin as output
	int get_value(std::string& value); //Get current value
	
	// Output functions
	int set_value(std::string value); //Set current value
	
	private:
	
	int pin;
};

#endif
