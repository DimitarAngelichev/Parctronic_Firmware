#ifndef PARKTRONIC_H
#define PARKTRONIC_H

#include <cluster.h>
#include <buzzer_p.h>

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
    // Protected за да може да се достъпва от тези които наследяват този клас.
    protected:
        Cluster *cluster_left;
        Cluster *cluster_center_left;
        Cluster *cluster_center_right;
        Cluster *cluster_right;
        AlarmBuzzer *alarm_buzzer;

        uint32_t current_cluster = 0;
        /* top dist level */
        uint32_t dist_level = 0;

    public:
        // C++11 инициализиране на променливите които се ползват за съхранение на текущото
        // състояние на машината на състоянията и на стойността на бутона.
        bool button_value = PARK_ASSIST_OFF;

        // Конструктора се ползва за инициализиране на поделементите на класа,
        // той не може да е виртуален.
        Parktronic() {
            this->cluster_left = new Cluster(1);
            this->cluster_center_left = new Cluster(2);
            this->cluster_center_right = new Cluster(3);
            this->cluster_right = new Cluster(4);
            this->alarm_buzzer = new AlarmBuzzer();
        }

        // Задължително е при виртуално наследяване деструктора да е виртуален.
        virtual ~Parktronic() {
            delete this->cluster_left;
            delete this->cluster_center_left;
            delete this->cluster_center_right;
            delete this->cluster_right;
            delete this->alarm_buzzer;
        }
        // Виртуална функция, която ще се override-ва
        // override - означава че се променя тялото на фукнцията по време на изпълнение
        virtual void state_machine();
        void distance_test();
        void off();
        void blink_once();
};

/**
 * @brief
 * Това е нормалното състояние на системата.
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
 */
class ParktronicStateExit : public ParktronicStateNormal {
    public:
    ParktronicStateExit() {}
        virtual void state_machine();
    virtual ~ParktronicStateExit() {

    }
};

#endif // PARKTRONIC_H
