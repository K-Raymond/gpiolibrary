// File: libgpiorpi.hpp

#ifndef rpi_pin_CLASS_H
#define rpi_pin_CLASS_H

#include <string>

class rpi_pin
{
	public:
	rpi_pin(); // Should never be run
	rpi_pin(int pin); //Create a gpio pin instance
	int export(); //export the pin
	int unexport(); //unexport the pin
	int intput(); //Set pin as input
	int output(); //Set pin as output
	
	// Output functions
	int set_value(string value); //Set current value
	int get_value(string& value); //Get current value
	
	private:
	int pin;
}

#endif