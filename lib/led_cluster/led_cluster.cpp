#include <led_cluster.h>
#include "../../include/pins.h"
#include <led.h>
#include <Arduino.h>
#include <parktronic.h>

LedCluster::LedCluster(int number)
{
    this->init(number);
}

void LedCluster::init(int nr)
{
    switch (nr) {
        case 1:
            Serial.print("init clust 1\n");

            this->green1 = new Led(LEDG1_1);
            this->green2 = new Led(LEDG1_2);
            this->green3 = new Led(LEDG1_3);
            this->yellow1 = new Led(LEDY1_1);
            this->yellow2 = new Led(LEDY1_2);
            this->yellow3 = new Led(LEDY1_3);
            this->red1 = new Led(LEDR1_1);
            this->red2 = new Led(LEDR1_2);
            this->red3 = new Led(LEDR1_3);
            break;
        case 2:

            this->green1 = new Led(LEDG2_1);
            this->green2 = new Led(LEDG2_2);
            this->green3 = new Led(LEDG2_3);
            this->yellow1 = new Led(LEDY2_1);
            this->yellow2 = new Led(LEDY2_2);
            this->yellow3 = new Led(LEDY2_3);
            this->red1 = new Led(LEDR2_1);
            this->red2 = new Led(LEDR2_2);
            this->red3 = new Led(LEDR2_3);
            break;
        case 3:

            this->green1 = new Led(LEDG3_1);
            this->green2 = new Led(LEDG3_2);
            this->green3 = new Led(LEDG3_3);
            this->yellow1 = new Led(LEDY3_1);
            this->yellow2 = new Led(LEDY3_2);
            this->yellow3 = new Led(LEDY3_3);
            this->red1 = new Led(LEDR3_1);
            this->red2 = new Led(LEDR3_2);
            this->red3 = new Led(LEDR3_3);
            break;
        case 4:

            this->green1 = new Led(LEDG4_1);
            this->green2 = new Led(LEDG4_2);
            this->green3 = new Led(LEDG4_3);
            this->yellow1 = new Led(LEDY4_1);
            this->yellow2 = new Led(LEDY4_2);
            this->yellow3 = new Led(LEDY4_3);
            this->red1 = new Led(LEDR4_1);
            this->red2 = new Led(LEDR4_2);
            this->red3 = new Led(LEDR4_3);
            break;
        default:
            break;
    }
}

extern Parktronic *park_assist;

void LedCluster::led_cluster_state_machine(int dist)
{
    //Serial.print("running led_cluster_state_machine for cluster 1\n");
    /* if level is higher than last, update the top dist level */
    if (dist > park_assist->dist_level) {
        park_assist->dist_level = dist;
    }

    switch (dist) {
        case 1:
            this->green1->blink_once();
            this->green2->off();
            this->green3->off();
            this->yellow1->off();
            this->yellow2->off();
            this->yellow3->off();
            this->red1->off();
            this->red2->off();
            this->red3->off();
            break;
        case 2:
            this->green1->on();
            this->green2->blink_once();
            this->green3->off();
            this->yellow1->off();
            this->yellow2->off();
            this->yellow3->off();
            this->red1->off();
            this->red2->off();
            this->red3->off();

            break;
        case 3:
            this->green1->on();
            this->green2->on();
            this->green3->blink_once();
            this->yellow1->off();
            this->yellow2->off();
            this->yellow3->off();
            this->red1->off();
            this->red2->off();
            this->red3->off();
            break;
        case 4:
            this->green1->on();
            this->green2->on();
            this->green3->on();
            this->yellow1->blink_once();
            this->yellow2->off();
            this->yellow3->off();
            this->red1->off();
            this->red2->off();
            this->red3->off();
            break;
        case 5:
            this->green1->on();
            this->green2->on();
            this->green3->on();
            this->yellow1->on();
            this->yellow2->blink_once();
            this->yellow3->off();
            this->red1->off();
            this->red2->off();
            this->red3->off();
            break;
        case 6:
            this->green1->on();
            this->green2->on();
            this->green3->on();
            this->yellow1->on();
            this->yellow2->on();
            this->yellow3->blink_once();
            this->red1->off();
            this->red2->off();
            this->red3->off();
            break;
        case 7:
            this->green1->on();
            this->green2->on();
            this->green3->on();
            this->yellow1->on();
            this->yellow2->on();
            this->yellow3->on();
            this->red1->blink_once();
            this->red2->off();
            this->red3->off();
            break;
        case 8:
            this->green1->on();
            this->green2->on();
            this->green3->on();
            this->yellow1->on();
            this->yellow2->on();
            this->yellow3->on();
            this->red1->on();
            this->red2->blink_once();
            this->red3->off();
            break;
        case 9:
            this->green1->on();
            this->green2->on();
            this->green3->on();
            this->yellow1->on();
            this->yellow2->on();
            this->yellow3->on();
            this->red1->on();
            this->red2->on();
            this->red3->blink_once();
            break;

        default:
            break;
    }
}