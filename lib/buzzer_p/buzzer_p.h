#ifndef BUZZER_P_H
#define BUZZER_P_H

#include <Buzzer.h>

#define B_PIN 13

class AlarmBuzzer
{
    private:
        int pin;
        Buzzer *buzzer;

    public:
        AlarmBuzzer();
        void init();
        void on();
        void off();
        void far();
        void close();
        void danger();
        void buzz_once();
        void buzzer_test();
};
#endif // BUZZER_P_H