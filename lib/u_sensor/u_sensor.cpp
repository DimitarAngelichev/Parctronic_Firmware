#include <u_sensor.h>


int USonicSensor::get_value(){
    return round(this->sensor->dist());
}
