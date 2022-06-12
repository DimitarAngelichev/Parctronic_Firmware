#ifndef LED_H
#define LED_H

class Led
{
    private:
        int pin;

    public:
        Led(int pin);
        void init();
        void on();
        void off();
        void blink_once();
        void delay(int time);
};
#endif // LED_H