#ifndef U_SENSOR_H
#define U_SENSOR_H

#include <HCSR04.h>
#include "../../include/pins.h"

class USonicSensor
{
    private:
        float dist;
        HCSR04 *sensor;

    public:
        USonicSensor(int nr) {
            switch (nr) {
                case 1:
                    this->sensor = new HCSR04(SEN1_TRIG, SEN1_ECHO);
                    break;
                case 2:
                    this->sensor = new HCSR04(SEN2_TRIG, SEN2_ECHO);
                    break;
                case 3:
                    this->sensor = new HCSR04(SEN3_TRIG, SEN3_ECHO);
                    break;
                case 4:
                    this->sensor = new HCSR04(SEN4_TRIG, SEN4_ECHO);
                    break;
                default:
                    break;
            }
        };
        
        int get_value();
        void on();
        void off();
        void blink_once();
};

#endif // U_SENSOR_H
