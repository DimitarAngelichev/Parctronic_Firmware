#ifndef CLUSTER_H
#define CLUSTER_H

#include <HCSR04.h>
#include <led_cluster.h>
#include <u_sensor.h>
#include "../../include/pins.h"

class Cluster
{
    private:
        LedCluster *ledCluster;
        USonicSensor *usonic_sensor;
        int cluster = 0;

    public:
        Cluster (int cluster_index) {
            this->ledCluster = new LedCluster(cluster_index);
            this->usonic_sensor = new USonicSensor(cluster_index);
            this->cluster = cluster_index;

        }
        void sonicsensor_test();
        void cluster_state_machine();
};
#endif // CLUSTER_H