#include <Arduino.h>
#include <buzzer_p.h>
#include <cluster.h>
#include <led_cluster.h>
#include <parktronic.h>
#include <new>


/** @brief
 * Дефиниране на асистента за паркиране, указателя ще се ползва за
 * включване и изключване на системата
 */
Parktronic *park_assist;

/** @brief
 * Функцията setup() се вика веднъж при инициализация на микроконтролера
 * инициализират се следните обекти и променливи:
 * - <опиши Serial.begin(9600);>
 * - <опиши pinMode(SWITCH_PIN, INPUT);>
 *
 */
void setup()
{
    Serial.begin(9600);

    // Тук се дефинира пин през който се чете за включено или изключено състояние
    pinMode(SWITCH_PIN, INPUT);

    /** Първо се инициализира обекта, който се намира на най - високо ниво в йерархията,
    * за да се задоволят изискванията за подравняване (Alignment)
    * Това е добра практика според стандарта
    * Ако това не се направи има неопределени последствия, тъй като ако той съдържа
    * подобекти които не фигурират по - надолу в йерархията, при сменяне на типа може да
    * се счупи програмата
    **/
    park_assist = new ParktronicStateExit{};

    // ~Parktronic вика виртуалния деструктор на park_assist, който ще извика всички деструктори
    // на текущия тип (ParktronicStateExit)
    park_assist->~Parktronic();

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
}
