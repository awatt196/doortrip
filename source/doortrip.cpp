/*
    DoorTrip.cpp -  DoorTrip sensor library
    Developed by Andrea Corrado & Eric Gowland
    
    Connect to a hardware device that is boolean present/not present. Such as PIR, Rangefinder or laser with appropriate signalling.
    Also drives LED as DoorTrip indicator.
*/


#include "mbed-drivers/mbed.h"
#include "doortrip/doortrip.h"



DoorTrip::DoorTrip(PinName pin, bool true_on_rise, int debounce_time_ms):_myint(pin), _led1(LED1)
{
    debounce_ms = debounce_time_ms;
    _true_on_rise = true_on_rise;
//    if(true_on_rise) {
//        _myint.rise(this, &DoorTrip::DoorTrip_interrupt_off);
//        _myint.fall(this, &DoorTrip::DoorTrip_interrupt_on);
//    } else {
//        _myint.rise(this, &DoorTrip::DoorTrip_interrupt_on);
//        _myint.fall(this, &DoorTrip::DoorTrip_interrupt_off);
//    }
    _detection=false;
//    debounce_timer.start();
    _led1=1;

}

void DoorTrip::DoorTrip_interrupt_off(){
    if(debounce_timer.read_ms() > debounce_ms) {
        _detection=false;
        _led1=1;
    }
}

void DoorTrip::DoorTrip_interrupt_on() //Detection of motion.
{
    //Always trigger detection..
    _detection=true;
    _led1=0;
    debounce_timer.reset(); // Reset counter to 0...
}

bool DoorTrip::isPresent(){
//    if (debounce_timer.read_ms() > debounce_ms) {
        //Poll the pin and update value...
        _detection = (_true_on_rise && _myint == 1) || (!_true_on_rise && _myint == 0);
        if(_detection) _led1 = 0; else _led1 = 1;
//    }
    return _detection;
}