#ifndef PARKTRONIC_H
#define PARKTRONIC_H

#include <cluster.h>
#include <buzzer_p.h>

enum {
    ON,
    OFF
} parktronic_states;

class Parktronic
{
    private:
        Cluster *cluster_left;
        Cluster *cluster_center_left;
        Cluster *cluster_center_right;
        Cluster *cluster_right;
        AlarmBuzzer *alarm_buzzer;
    public:
        Parktronic(){
            this->cluster_left = new Cluster(1); 
            this->cluster_center_left = new Cluster(2);
            this->cluster_center_right = new Cluster(3);
            this->cluster_right = new Cluster(4);
            this->alarm_buzzer= new AlarmBuzzer();
        }

        void state_machine(parktronic_states state);
        void distance_test();
        void off();
        void blink_once();
};

#endif // PARKTRONIC_H
