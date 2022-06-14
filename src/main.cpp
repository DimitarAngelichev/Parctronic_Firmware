#include <Arduino.h>
#include <buzzer_p.h>
#include <cluster.h>
#include <led_cluster.h>
#include <parktronic.h>


/** @brief
 * Деклариране на асистента за паркиране, указателя ще се ползва за
 * включване и изключване на системата
 */
Parktronic *park_assist;

Cluster cluster1(1); // test

/** @brief
 * Функцията setup() се вика веднъж при инициализация на микроконтролера
 * инициализират се следните обекти и променливи:
 * - <опиши Serial.begin(9600);>
 * -  <опиши pinMode(BUTTON_PIN, INPUT);>
 *
 */
void setup()
{
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT);

    // Пресъздава се обекта с ново състояние - ParktronicStateNormal - началното състояние
    // на машината
    park_assist = new ParktronicStateNormal{};
}

/** @brief
 * Функцията loop() е от Arduino.h библиотеката, това е безкраен цикъл и чрез нея системата работи
 * в реално време
 */
void loop()
{

    park_assist->state_machine();

    // cluster1.cluster_state_machine();
    // start system

}

// button_value = digitalRead(BUTTON_PIN);

// if (0 != button_value) {
//     if (PARK_ASSIST_OFF == park_assist.park_assist_state) {
//         park_assist.state_machine(PARK_ASSIST_ON);
//     } else {
//         park_assist.state_machine(PARK_ASSIST_OFF);
//     }
// }