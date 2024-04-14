#pragma once
#include "Enemy1.h"
#include "Items.h"
#include "Inventory.h"
#include "PlayerStats.h"
#include <iostream>
#include <random>

using namespace std; 
srand((unsigned)time(NULL));

int playerattack() {
    int roll = 0;
    roll = rand() % 6 + 1;
    if (Player.getStrength() >= 40) {
        if (roll >= 2) {
            Boss.setHealth(90);
        }

        else (roll < 2) {
            Boss.setHealth(80);
        }
    };
    else (Player.getStrength() < 40) {
        if (roll >= 4) {
            Boss.Health(90);
        }

        else (roll < 4) {
            Boss.setHealth(80);
        }
    };

    return Boss.getHealth();
};

int enemyattack() {
    int roll = 0;
    roll = rand() % 6 + 1;
    if (Boss.getStrength() >= 50) {
        if (roll >= 2) {
            Player.setHealth(90);

        }
        else (roll < 2) {
            Player.setHealth(80);
        }
    };
    else (Boss.getStrength() = < 50) {
        if (roll >= 4) {
            Player.setHealth(90);
        }
        else (roll < 4) {
            Player.setHealth(80);
        }
    };
    return Player.getHealth();
};

int enemyheal() {
    if (Boss.getHealth() < 10) {
        int roll = 0;
        roll = rand() % 6 + 1;

        if (roll > 4) {
            10 + Boss.setHealth();
        }
    };
    return Boss.getHealth();
};

int enemyflee() {

};

int Fighting() {

};
