#ifndef CLUSTER_H
#define CLUSTER_H

#include <HCSR04.h>
#include <led_cluster.h>
#include <u_sensor.h>
#include "../../include/pins.h"

class Cluster
{
    private:
        // class LedClister;
        //HCSR04 *hc;
        LedCluster *ledCluster;
        USonicSensor *usonic_sensor;
        int clusternr=0;
        
    public:
        Cluster (int cluster_nr) {
            this->ledCluster = new LedCluster(cluster_nr);
            this->usonic_sensor = new USonicSensor(cluster_nr);
            this->clusternr=cluster_nr;
            
        }
        // void on();
        // void off();
        void sonicsensor_test();
        void cluster_state_machine();
};
#endif // CLUSTER_H