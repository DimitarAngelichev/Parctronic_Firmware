#include <parktronic.h>

// Parktronic::Parktronic()
// {

// }

void Parktronic::state_machine (parktronic_states state) {
    switch (state) {
        case PARK_ASSIST_ON:
            //parktronic On
            this->park_assist_state = PARK_ASSIST_ON;
            this->alarm_buzzer->on();
            break;
        case PARK_ASSIST_OFF:
            //parktronic off
            this->park_assist_state = PARK_ASSIST_OFF;
            this->alarm_buzzer->off();

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