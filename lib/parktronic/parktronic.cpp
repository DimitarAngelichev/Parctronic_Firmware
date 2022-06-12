#include <parktronic.h>

Parktronic::Parktronic();
{

}

void Parktronic::state_machine (parktronic_states state) {
    switch (state) {
        case ON:
            //parktronic On

            break;
        case OFF:
            //parktronic off
            
        default:
            break;
    }

}

void Parktronic::distance_test () {

}

void Parktronic::off () {

}

void Parktronic::blink_once () {

}