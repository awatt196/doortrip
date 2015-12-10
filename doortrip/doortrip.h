/*
    DoorTrip.cpp -  DoorTrip sensor library
    Developed by Andrea Corrado & Eric Gowland
    
    Connect to a hardware device that is boolean present/not present. Such as PIR, Rangefinder or laser with appropriate signalling.
    Also drives LED as DoorTrip indicator.
*/


#ifndef MBED_DOOR_H
#define MBED_DOOR_H

#include "mbed-drivers/mbed.h"

class DoorTrip{
    
public:

    DoorTrip(PinName pin, bool true_on_rise, int debounce_time_ms);
    bool isPresent();
    
private:
    InterruptIn _myint;
    DigitalOut _led1;
    bool _detection;
    bool _true_on_rise;
    int debounce_ms;
    Timer debounce_timer;
    void DoorTrip_interrupt_on();
    void DoorTrip_interrupt_off();
    
};

#endif