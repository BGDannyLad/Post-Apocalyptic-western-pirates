#pragma once
#include "Enemy1.h"
#include "Items.h"
#include "Inventory.h"
#include "PlayerStats.h"
#include <iostream>
#include <random>

using namespace std; 

int playerattack() {
    int roll = 0;
    roll = rand() % 6 + 1;
    if (Player.Strength >= 40) {
        if (roll >= 2) {
            Boss.Health - 10;
        }

        else (roll < 2) {
            Boss.Health - 20;
        }
    }
    else (Player.Strength < 40) {
        if (roll >= 4) {
            Boss.Health - 10;
        }

        else (roll < 4) {
            Boss.Health - 20;
        }
    }
    
}

int enemyattack() {
    int roll = 0;
    roll = rand() % 6 + 1;
    if (Boss.Strength >= 50) {
        if (roll >= 2) {
            Player.Health - 10;

        }
        else (roll < 2) {
            Player.Health - 20;
        }
    }
        else (Boss.Strength = < 50) {
            if (roll >= 4) {
                Player.Health - 10;
            }
            else (roll < 4) {
                Player.Health - 20;
            }
        }
}

int enemyheal(){
	if (Boss.Health < 10) {
        int roll = 0; 
        roll = rand() % 6 + 1;

        if (roll > 4) { 
            10 + Boss.Health;
        }
	}
}

int enemyflee(){

}

int Fighting() {

}
