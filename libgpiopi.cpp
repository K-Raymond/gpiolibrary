// File: libgpiorpi.cpp

// Compile with -std=c++11

#include <fstream>
#include <string>
#include "libgpiopi.hpp"

rpi_pin::rpi_pin()
{
	// Do not run!
}

rpi_pin::rpi_pin( int new_pin ) : pin( new_pin )
{
	// Standard constructor
}

int rpi_pin::export()
{
	std::ofstream export_file( "/sys/class/gpio/export" );
	if ( export_file < 0 )
	{
		//error
		return -1;
	}
	export_file << pin;
	export_file.close();
	return 0;
}

int rpi_pin::unexport()
{
	std::ofstream unexport_file( "/sys/class/gpio/unexport" )
	if (unexport_file < 0 )
	{
		//error
		return -1;
	}
	unexport_file << pin;
	unexport_file.close();
	return 0;
}

int rpi_pin::input()
{
	std::ofstream fdirection( "/sys/class/gpio" + std::to_string(pin) + "/direction" );
	if (unexport_file < 0 )
	{
		//error
		return -1;
	}
	fdirection << "in";
	fdirection.close();
	return 0;
}

int rpi_pin::output()
{
	std::ofstream fdirection( "/sys/class/gpio" + std::to_string(pin) + "/direction" );
	if (unexport_file < 0 )
	{
		//error
		return -1;
	}
	fdirection << "out";
	fdirection.close();
	return 0;
}

int rpi_pin::set_value( string value )
{
	std::ofstream fvalue( "/sys/class/gpio" + std::to_string(pin) + "/value" );
	if ( fvalue < 0 )
	{
		// error
		return -1;
	}
	fvalue << value;
	fvalue.close();
	return 0;
}

int rpi_pin::get_value( string& value )
{
	std::ofstream fvalue( "/sys/class/gpio" + std::to_string(pin) + "/value" );
	if ( fvalue < 0 )
	{
		// error
		return -1;
	}
	fvalue >> value;
	fvalue.close();
	return 0;
}