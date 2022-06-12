#include <Arduino.h>
#include <buzzer_p.h>
#include <cluster.h>
#include <led_cluster.h>

AlarmBuzzer buzzer;
//setup all leds and sonic sensors

Cluster cluster1(1);
// Cluster cluster2(2);
// Cluster cluster3(3);
// Cluster cluster4(4);

LedCluster ledcluster1(1);
void setup()
{
    Serial.begin(9600);

}

void loop()
{
    //ledcluster1.LedClusterTest();

    cluster1.cluster_state_machine();
    // cluster2.cluster_state_machine();
    // cluster3.cluster_state_machine();
    // cluster4.cluster_state_machine();
    // start system

}