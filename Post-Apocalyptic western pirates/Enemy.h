#pragma once
#include <iostream>
#include "Inventory.h"
#include "Items.h"
#include <string>
#include "Player.h"
using namespace std;


class Enemy {
private:
	int health, strength, smarts, dexterity, type, maxHealth;
	inventory* EnemyInv;
	Enemy* next;
	Enemy* last;
	string name;
public:
	Enemy(int muscles, int intelligence, int dex, int typ, int maxH, string nme, inventory* inv) {
		strength = muscles;
		smarts = intelligence;
		dexterity = dex;
		type = typ;
		maxHealth = maxH;
		health = maxH;
		EnemyInv = inv;
		name = nme;
	}
	Enemy* getNext() {
		return next;
	}
	Enemy* setName(string nam) {
		name = nam;
	}
	string getName() {
		return name;
	}
	void setNext(Enemy* nxt) {
		next = nxt;
	}
	Enemy* getLast() {
		return last;
	}
	void setLast(Enemy* lst) {
		last = lst;
	}
	int getType() {
		return type;
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
	void changeHand(int id) {
		item* swapto = EnemyInv->search(id);
		if (swapto == NULL) {
			std::cout << "item does not exist." << std::endl;
		}
		else if (swapto->getCount() <= 0) {
			std::cout << "You dont have the target item." << std::endl;
		}
		else {
			EnemyInv->setCurrent(swapto);
		}
	}
	item* getHand() {
		return EnemyInv->getCurrent();
	}
	/*void useHand(Player* target) {
		int id = EnemyInv->getCurrent()->getID();
		if (id == 1) {
			std::cout << "Used dagger" << std::endl;
		}
		else if (id == 2) {
			std::cout << "used wiggly fish";
		}
	}*/
	inventory* getInventory() {
		return EnemyInv;
	}
	void setInventory(inventory* newInv) {
		EnemyInv = newInv;
	}
	void displayStuff() {
		cout << "Name: " << getName() << ", Strength: " << getStrength() << ", intelligence: " << getSmarts() << ", dex: " << getDexterity() << ", max health: " << getHealth() << ", Inventory: ";
		EnemyInv->display();
	}
};
//int health, strength, smarts, dexterity, type, maxHealth;
//inventory* EnemyInv;
//Enemy* next;
//Enemy* last;
//string name;