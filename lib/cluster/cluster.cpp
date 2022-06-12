#include <cluster.h>


void Cluster::sonicsensor_test()
{
    Serial.println (this->usonic_sensor->get_value ());
    delay(60);
}

 void  Cluster::cluster_state_machine () {

    int dist = this->usonic_sensor->get_value ();
    Serial.print("Cluster Nr: ");
    Serial.print(this->cluster);
    Serial.print(" Distance to Object: ");
    Serial.print(dist);
    Serial.print(" Setting: ");

    if (dist > 150 && dist < 200) {
        this->ledCluster->LedClusterTest(1);
        Serial.println("farthest");
    } else if (dist > 120 && dist < 150) {
        this->ledCluster->LedClusterTest(2);
        Serial.println("farther");
    } else if (dist > 90 && dist < 120) {
        this->ledCluster->LedClusterTest(3);
        Serial.println("far");
    } else if (dist > 70 && dist < 90) {
        this->ledCluster->LedClusterTest(4);
        Serial.println("medium");
    } else if (dist > 50 && dist < 70) {
        this->ledCluster->LedClusterTest(5);
        Serial.println("mediumer");
    } else if (dist > 30 && dist < 50 ) {
        this->ledCluster->LedClusterTest(6);
        Serial.println("mediumest");
    } else if (dist > 20 && dist < 30) {
        this->ledCluster->LedClusterTest(7);
        Serial.println("close");
    } else if (dist > 10 && dist < 20) {
        this->ledCluster->LedClusterTest(8);
        Serial.println("closer");
    } else if (dist < 10 && dist != 0) {
        this->ledCluster->LedClusterTest(9);
        Serial.println("closest");
    }
}