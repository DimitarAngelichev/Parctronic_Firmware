#include "Arduino.h"
#include "led.h"

#define PWM_Res 8
#define PWM_Freq 1000

Led::Led(int pin)
{
    this->pin = pin;
    init();
}

void Led::init()
{
    pinMode(this->pin, OUTPUT);
    off();
}

void Led::on()
{
    digitalWrite(this->pin, HIGH);
}

void Led::delay(int time)
{
    unsigned long curr_time = 0;
    curr_time = millis();
    while (millis() < curr_time + time);
}

void Led::off()
{
    digitalWrite(this->pin, LOW);
}

void Led::blink_once()
{
    this->on();
    this->delay(50);
    this->off();
}
