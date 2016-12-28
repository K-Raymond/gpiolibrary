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
    if( led.pin_export() == 0 )
        cout << "Pin exported" << endl;
    else
     {cout << "Error Exporting" << endl; return -1;}
    if( led.output() == 0 )
        cout << "pin set as output" << endl;
    else
        {cout << "couldn't set pin as output" << endl; return -1;}
    
    unsigned int i = 0;
    while (i<6)
    {
        cout << "interation: " << i+1 << endl;
        usleep(sleeptime * 1000); //microseconds
        if ( led.set_value("1") == -1 )
            cout << "error setting value 1" << endl;
        usleep(sleeptime * 1000);
        if ( led.set_value("0") == -1 )
            cout << "error setting value 0" << endl;
        i++;
    }
    
    // cleanup
    led.pin_unexport();
    return 0;
}