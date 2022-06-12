#include <buzzer_p.h>

AlarmBuzzer::AlarmBuzzer()
{
    this->buzzer = new Buzzer(B_PIN);
    digitalWrite(B_PIN, LOW);
}

void AlarmBuzzer::on()
{
    this->buzzer->begin(0);
    this->buzzer->sound(NOTE_C6, 250);
    this->buzzer->sound(NOTE_C6, 250);
    this->buzzer->sound(NOTE_C6, 250);
    this->buzzer->sound(NOTE_C6, 250);
    this->buzzer->end(1000);
}

void AlarmBuzzer::off()
{
    this->buzzer->begin(0);
    this->buzzer->sound(NOTE_C6, 750);
    this->buzzer->end(1000);
}

void AlarmBuzzer::far()
{
    this->buzzer->begin(0);
    this->buzzer->sound(NOTE_C6, 1000);
    this->buzzer->end(1000);
}

void AlarmBuzzer::close()
{
    this->buzzer->begin(0);
    this->buzzer->sound(NOTE_C6, 500);
    this->buzzer->end(1000);
}

void AlarmBuzzer::danger()
{
    this->buzzer->begin(5);
    this->buzzer->sound(NOTE_C6, 50);
    this->buzzer->end(10);
}

void AlarmBuzzer::buzz_once()
{
    this->buzzer->begin(5);
    this->buzzer->sound(NOTE_C6, 1000);
    this->buzzer->end(10);
}

void AlarmBuzzer::buzzer_test()
{
    Serial.print("on");
    delay(1000);
    this->on();
    Serial.print("far");
    delay(1000);
    this->far();

    Serial.print("close");
    delay(1000);
    this->close();

    Serial.print("danger");
    delay(1000);
    this->danger();
}