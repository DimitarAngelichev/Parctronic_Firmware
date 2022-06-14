#ifndef CLUSTER_H
#define CLUSTER_H

#include <HCSR04.h>
#include <led_cluster.h>
#include <u_sensor.h>
#include "../../include/pins.h"

/**
 * @brief
 *
*/
class Cluster
{
    public:
        LedCluster *ledCluster;      // Деклариране на група светлодиоди
        USonicSensor *usonic_sensor; // и ултразвуков сензор към тях.

        // Конструктора на групата.
        Cluster (int cluster_index) {
            // Алокиране и инициализиране на LedCluster
            this->ledCluster = new LedCluster(cluster_index);
            // Алокиране и инициализиране на USonicSensor
            this->usonic_sensor = new USonicSensor(cluster_index);
        }

        void cluster_state_machine();
};
#endif // CLUSTER_H