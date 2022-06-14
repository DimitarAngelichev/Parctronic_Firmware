#ifndef PARKTRONIC_H
#define PARKTRONIC_H

#include <cluster.h>
#include <buzzer_p.h>

// Енумератор за включено и изключено състояние
enum parktronic_states {
    PARK_ASSIST_OFF,
    PARK_ASSIST_ON
};

/**
 * @brief
 * Този клас е базов клас на полиморфичен обект,
 * който се използва като машина на състоянията - state mchine.
*/
class Parktronic
{
    // Публичен, за да може да се достъпва от тези които наследяват този клас.
    public:
        // Тук са декларирани четирите групи - сезнор със светлодиодите, които принадлежат на
        // неговата група.
        Cluster *cluster_left;
        Cluster *cluster_center_left;
        Cluster *cluster_center_right;
        Cluster *cluster_right;
        AlarmBuzzer *alarm_buzzer; // Активния зумер, който се ползва за звуковата сигнализация.

        // C++11 инициализиране на променливите които се ползват за съхранение на текущото
        // състояние на машината на състоянията и на стойността на бутона.
        bool switch_value = PARK_ASSIST_OFF;

        // Конструктора се ползва за инициализиране на поделементите на класа,
        // той не може да е виртуален.
        Parktronic() {
            this->cluster_left = new Cluster(1);           // Създаване на групите динамично
            this->cluster_center_left = new Cluster(2);    // чрез new().
            this->cluster_center_right = new Cluster(3);
            this->cluster_right = new Cluster(4);
            this->alarm_buzzer = new AlarmBuzzer();       // Динамично създаване на зумера.
        }

        // Задължително е при виртуално наследяване деструктора да е виртуален.
        virtual ~Parktronic() {
            delete this->cluster_left;          // Освобождаване на памет
            delete this->cluster_center_left;
            delete this->cluster_center_right;
            delete this->cluster_right;
            delete this->alarm_buzzer;
        }

        // Виртуална функция, която ще се override-ва
        // override - означава че се променя тялото на фукнцията по време на изпълнение
        virtual void state_machine() = 0;
};

/**
 * @brief
 * Това е нормалното състояние на системата.
 * В това състояние на системата ...
 * ParktronicStateNormal наследява Parktronic и overrideва виртуалната функция state_machine()
 * както и виртуалния диструктор. Когато се изпълни обект от този тип се изпълняват функциите, които
 * са в типа не зависимо как е зададен първоначално.
 */
class ParktronicStateNormal : public Parktronic {
    public:
    ParktronicStateNormal() {}
        virtual void state_machine();
    virtual ~ParktronicStateNormal() {

    }
};

/**
 * @brief
 * Това е състоянието за изход от системата.
 * По същия начин като ParktronicStateNormal, но в случая се наследява ParktronicStateNormal,
 * така се наследява Parktronic, но пак се overrideват state_machine() и диструктора.
 */
class ParktronicStateExit : public ParktronicStateNormal {
    public:
    ParktronicStateExit() {}
        virtual void state_machine();
    virtual ~ParktronicStateExit() {

    }
};

#endif // PARKTRONIC_H
