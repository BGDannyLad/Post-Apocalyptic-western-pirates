#pragma once
#include "Enemy1.h"
#include "Items.h"
#include "Inventory.h"
#include <iostream>\
#include <random>

using namespace std; 


int playerattack() {

}

int enemyattack() {
    int roll = 0;
    roll = rand() % 6 + 1;
    if (Enemy.strength >= 50) {
        if (roll >= 2) {
            player.health - 10;

        }
        else (roll < 2) {
            player.health - 20;
        }
    }
        else (Enemy.strength = < 50) {
            if (roll >= 4) {
                player.health - 10;
            }
                else (roll < 4) {
                player.health - 20;
                }
        }
}

int enemyheal(){
	if (health < 10) {
        int roll = 0; 
        roll = rand() % 6 + 1;

        if (roll > 4) { 
            10 + Boss.health;
        }
	}
}

int enemyflee(){

}

int Fighting() {

}
