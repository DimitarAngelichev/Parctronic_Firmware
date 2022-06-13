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

    /** Първо се инициализира обекта, който се намира на най - високо ниво в йерархията,
      * за да се задоволят изискванията за подравняване (Alignment)
      * Това е добра практика според стандарта
      * Ако това не се направи има неопределени последствия, тъй като ако той съдържа
      * подобекти които не фигурират по - надолу в йерархията, при сменяне на типа може да
      * се счупи програмата
    **/
    park_assist = new ParktronicStateExit();

    // ~decltype вика виртуалния деструктор на park_assist, който ще извика всички деструктори
    // на текущия тип (ParktronicStateExit)
    park_assist->~decltype(park_assist)();

    // Пресъздава се обекта с ново състояние - ParktronicStateNormal - началното състояние
    // на машината
    new (park_assist) ParktronicStateNormal{};
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