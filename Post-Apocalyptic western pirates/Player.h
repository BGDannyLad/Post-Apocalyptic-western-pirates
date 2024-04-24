#pragma once
#include <iostream>
#include "Inventory.h"
#include "Items.h"
#include "Entity.h"


class Player {
private:
	int health, strength, smarts, dexterity, seduction, money, type, maxHealth;
	inventory* playerInv;
	Player* next;
	Player* last;
	string name;
public:
	Player(int vitality, int muscles, int intelligence, int dex, int attractiveness, int mony, int typ, int maxH,string nme, inventory* inv) {
		health = vitality;
		strength = muscles;
		smarts = intelligence;
		dexterity = dex;
		seduction = attractiveness;
		money = mony;
		type = typ;
		maxHealth = maxH;
		playerInv = inv;
		name = nme;
	}
	Player* getNext() {
		return next;
	}
	Player* setName(string nam) {
		name = nam;
	}
	string getName() {
		return name;
	}
	void setNext(Player* nxt) {
		next = nxt;
	}
	Player* getLast() {
		return last;
	}
	void setLast(Player* lst) {
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
	void setSeduction(int s) {
		seduction = s;
	}
	void addMoney(int dollah) {
		money = money + dollah;
	}
	int getMoney() {
		return money;
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
	void changeHand(int id) {
		item* swapto = playerInv->search(id);
		if (swapto == NULL) {
			std::cout << "item does not exist." << std::endl;
		}
		else if (swapto->getCount() <= 0) {
			std::cout << "You dont have the target item." << std::endl;
		}
		else {
			playerInv->setCurrent(swapto);
		}
	}
	item* getHand() {
		return playerInv->getCurrent();
	}
	void useHand(Player* target) {
		int id = playerInv->getCurrent()->getID();
		if (id == 1) {
			std::cout << "Used dagger" << std::endl;
		}
		else if (id == 2) {
			std::cout << "used wiggly fish";
		}
	}
	inventory* getInventory() {
		return playerInv;
	}
	void setInventory(inventory* newInv) {
		playerInv = newInv;
	}
};
