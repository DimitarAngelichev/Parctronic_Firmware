#include <cluster.h>

void  Cluster::cluster_state_machine () {

    int dist = this->usonic_sensor->get_value ();

    if (dist > 150 && dist < 200) {
        this->ledCluster->led_cluster_state_machine(1);
    } else if (dist > 120 && dist < 150) {
        this->ledCluster->led_cluster_state_machine(2);
    } else if (dist > 90 && dist < 120) {
        this->ledCluster->led_cluster_state_machine(3);
    } else if (dist > 70 && dist < 90) {
        this->ledCluster->led_cluster_state_machine(4);
    } else if (dist > 50 && dist < 70) {
        this->ledCluster->led_cluster_state_machine(5);
    } else if (dist > 30 && dist < 50 ) {
        this->ledCluster->led_cluster_state_machine(6);
    } else if (dist > 20 && dist < 30) {
        this->ledCluster->led_cluster_state_machine(7);
    } else if (dist > 10 && dist < 20) {
        this->ledCluster->led_cluster_state_machine(8);
    } else if (dist < 10 && dist != 0) {
        this->ledCluster->led_cluster_state_machine(9);
    } else {
        this->ledCluster->dist_level = 0;
    }
}