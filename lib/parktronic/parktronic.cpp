#include <parktronic.h>

// Parktronic::Parktronic()
// {

// }

void ParktronicStateNormal::state_machine () {
    auto arrayclusters[] = {cluster_left, cluster_left,
                            cluster_center_right, cluster_right};

    dist_level = 0;

    for (auto cluster : arrayclusters) {
        // Включване на машината на състоянията поред на clusterите
        cluster->cluster_state_machine();

        /**
         * когато един сензор изпрати сигнал за измерване е възможно друг да прочете този сигнал,
         * това е нежелан ефект. За целта е необходим delay() от 60 милисекунди,
         * за да няма конфликт от един сензор до друг сензор
         */
        delay(60)
    }
    /* Beep according the highest score */
    switch (dist_level) {
        case 1:
        case 2:
            alarm_buzzer->far();
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            alarm_buzzer->close();
            break;
        case 8:
        case 9:
            alarm_buzzer->danger();
            break;

        default:
    }

    button_value = digitalRead(BUTTON_PIN);

    if (0 != button_value) {
        this->alarm_buzzer->off();
        /** Първо се инициализира обекта, който се намира на най - високо ниво в йерархията,
         * за да се задоволят изискванията за подравняване (Alignment)
         * Това е добра практика според стандарта
         * Ако това не се направи има неопределени последствия, тъй като ако той съдържа
         * подобекти които не фигурират по - надолу в йерархията, при сменяне на типа може да
         * се счупи програмата
        **/

        // ~decltype вика виртуалния деструктор на park_assist, който ще извика всички деструктори
        // на текущия тип (ParktronicStateExit)
        this->~Parktronic();
        new (this) ParktronicStateExit{};
    }
}

void ParktronicExit::state_machine() {
    //parktronic off
    this->alarm_buzzer->off();

    button_value = digitalRead(BUTTON_PIN);

    if (0 != button_value) {
        this->alarm_buzzer->on();
        this->~Parktronic(); //
        new (this) ParktronicStateNormal{};
    }
}

void Parktronic::distance_test () {

}

void Parktronic::off () {

}

void Parktronic::blink_once () {

}