#include <parktronic.h>

// Parktronic::Parktronic()
// {

// }

void ParktronicStateNormal::state_machine () {
    auto arrayclusters[] = {cluster_left, cluster_left,
                            cluster_center_right, cluster_right};


    for (auto cluster : arrayclusters) {
        cluster->cluster_state_machine();
        // delay (1ns) delay for the wave of a sensor to return
    }

    button_value = digitalRead(BUTTON_PIN);

    if (0 != button_value) {
        this->alarm_buzzer->off();
        this->~decltype(this)();
        new (this) ParktronicStateExit{};
    }
}

void ParktronicExit::state_machine() {
        //parktronic off
    this->alarm_buzzer->off();

    button_value = digitalRead(BUTTON_PIN);

    if (0 != button_value) {
        this->alarm_buzzer->on();
        this->~decltype(this)(); //
        new (this) ParktronicStateNormal{};
    }
}

void Parktronic::distance_test () {

}

void Parktronic::off () {

}

void Parktronic::blink_once () {

}