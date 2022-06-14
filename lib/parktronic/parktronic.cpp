#include <parktronic.h>
#include <new> // Включва placement new()



/**
 * Състоянието в което е включен асистента за паркиране, нормалното състояние на системата.
 * Тук се включват последователно групите на сензорите, това се случва с цел да няма конфликт
 * между един сензор с друг.
 */
void ParktronicStateNormal::state_machine () {
    Cluster  *arrayclusters[] = {cluster_left, cluster_left, // Масив от четирите групи.
                                 cluster_center_right, cluster_right};

    auto max_dist_level = 0; // Ползва се за задаване и нулиране на най - близката дистанция
    // засечена от един от сензорите за зумера.

    for (auto cluster : arrayclusters) { // Обхождат се четирите групи.
        // Включване на машината на състоянията поред на clusterите
        cluster->cluster_state_machine(); // Повиква се машината управляваща групата в тази итерация
        // на цикъла.

        // За да е коректен звуковия сигнал - ако един от сензорите е по - близко до обект,
        // то трябва зумера да отрази това, както и при промяна на това състояние от един сензор
        // към друг или от една дистанция към друга на същия сензор.
        if (cluster->ledCluster->dist_level > max_dist_level) {
            max_dist_level = cluster->ledCluster->dist_level;
        }

        // Тази проверка е необходима при изключване на системата по време на работа
        // в един цикъл на функционирането на сензорите.
        if(digitalRead(SWITCH_PIN) == 0) {
            break;
        }

        /**
         * Когато един сензор изпрати сигнал за измерване е възможно друг да прочете този сигнал,
         * това е нежелан ефект. За целта е необходим delay() от 1 милисекунда,
         * за да няма конфликт от един сензор до друг сензор.
         */
        delay(1);
    }

    // Зумера издава звук според най - късата възможна дистанция.
    switch (max_dist_level) {
        case 1:
        case 2:
        case 3:
            alarm_buzzer->far();
            break;
        case 4:
        case 5:
        case 6:
            alarm_buzzer->close();
            break;
        case 7:
        case 8:
        case 9:
            alarm_buzzer->danger();
            break;

        default:
            break;
    }

    // За проверка дали системата е изключена по време на изпълнение извън цикъла на изреждане на
    // всички групи.
    switch_value = digitalRead(SWITCH_PIN);

    if (0 == switch_value) {
        this->alarm_buzzer->off(); // Сигнал за изключване.

        // Извиква се диструктора на текущия обект и се създава на негово място новото състояние.
        this->~Parktronic();
        new (this) ParktronicStateExit{};
    }
}

void ParktronicStateExit::state_machine() {
    // За проверка дали системата е изключена по време на изпълнение извън цикъла на изреждане на
    // всички групи.
    switch_value = digitalRead(SWITCH_PIN);

    if (0 != switch_value) {
        this->alarm_buzzer->on(); // Сигнал за включване.
        // Извиква се диструктора на текущия обект и се създава на негово място новото състояние.
        this->~Parktronic(); //
        new (this) ParktronicStateNormal{};
    }
}
