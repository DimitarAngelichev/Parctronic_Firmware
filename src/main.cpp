#include <Arduino.h>
#include <buzzer_p.h>
#include <cluster.h>
#include <led_cluster.h>
#include <parktronic.h>

int button_value = 0;

// AlarmBuzzer buzzer;

//setup all leds and sonic sensors
Parktronic park_assist;

Cluster cluster1(1);
// Cluster cluster2(2);
// Cluster cluster3(3);
// Cluster cluster4(4);

LedCluster ledcluster1(1);
void setup()
{
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT);

}

void loop()
{
    button_value = digitalRead(BUTTON_PIN);

    if (0 != button_value) {
        if (PARK_ASSIST_OFF == park_assist.park_assist_state) {
            park_assist.state_machine(PARK_ASSIST_ON);
        } else {
            park_assist.state_machine(PARK_ASSIST_OFF);
        }
    }

    //ledcluster1.LedClusterTest();
    // cluster1.cluster_state_machine();
    // cluster2.cluster_state_machine();
    // cluster3.cluster_state_machine();
    // cluster4.cluster_state_machine();
    // start system

}