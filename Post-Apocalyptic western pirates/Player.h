#pragma once
#include <iostream>
#include "Inventory.h"
#include "Items.h"
#include "Entity.h"


class Player {
private:
	int health, strength, smarts, dexterity, seduction;
	inventory* playerInv;
public:
	Player(int vitality, int muscles, int intelligence, int dex, int attractiveness, inventory* inv) {
		health = vitality;
		strength = muscles;
		smarts = intelligence;
		dexterity = dex;
		seduction = attractiveness;		
	}
	void setHealth(int h) {
		health = h;
	}
	void setStrength(int s) {
		strength = s;
	}
	void setSmarts(int s) {
		smarts = s;
	}
	void setDexterity(int d) {
		dexterity = d;
	}
	void setSeduction(int s) {
		seduction = s;
	}
	int getHealth() {
		return health;
	}
	int getStrength() {
		return strength;
	}
	int getSmarts() {
		return smarts;
	}
	int getDexterity() {
		return dexterity;
	}
	int getSeduction() {
		return seduction;
	}
	void changeHand(item* newhand) {
		playerInv->setCurrent(newhand);
	}
	void useHand() {
		playerInv->getCurrent()->useitem()
	}
};
