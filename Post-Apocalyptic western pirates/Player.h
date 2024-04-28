#pragma once
#include <iostream>
#include "Inventory.h"
#include "Items.h"
#include "Enemy.h"
#include<cstdlib>

class Player {
private:
	int health, strength, smarts, dexterity, seduction, money, maxHealth;
	inventory* playerInv;
	string name;
public:
	Player(int muscles, int intelligence, int dex, int attractiveness, int mony, int maxH,string nme, inventory* inv) {
		srand((unsigned)time(NULL));
		health = maxH;
		strength = muscles;
		smarts = intelligence;
		dexterity = dex;
		seduction = attractiveness;
		money = mony;
		maxHealth = maxH;
		playerInv = inv;
		name = nme;
	}
	void setName(string nam) {
		name = nam;
	}
	string getName() {
		return name;
	}
	int getMaxHealth() {
		return maxHealth;
	}
	void setMaxHealth(int h) {
		maxHealth = maxHealth + h;
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
	void useHand(Enemy* target) {
		int id = playerInv->getCurrent()->getID();
		if (id == 1) {//half broken dagger
			std::cout << "Used half broken dagger" << std::endl;
			int randDamage = 1 + rand() % 3;
			int damage = getStrength() + randDamage;
			target->setHealth(target->getHealth() - damage);
			std::cout << "You stabbed" << target->getName() << " for " << damage << "damage." << std::endl;
		}

		else if (id == 2) {//Dried Fish
			std::cout << "Used dried fish" << std::endl;
			int randDamage = 7;
			int damage = getStrength() + randDamage;
			target->setHealth(target->getHealth() - damage);
			std::cout << "You force fed" << target->getName() << " for " << damage << "damage." << std::endl;
		}

		else if (id == 3) {//Cactus Sword
			std::cout << "Used cactus sword" << std::endl;
			int randDamage = 3 + rand() % 5;
			int damage = getDexterity() + randDamage;
			target->setHealth(target->getHealth() - damage);
			std::cout << "You poked" << target->getName() << " for " << damage << "damage." << std::endl;
		}

		else if (id == 4) {//Blunderbuss
			std::cout << "Used blunderbuss" << std::endl;
			int randDamage = 10;
			int damage = getSmarts() + randDamage; 
			target->setHealth(target->getHealth() - damage);
			std::cout << "You aimed and shot " << target->getName() << " for " << damage << "damage." << std::endl;
		}

		else if (id == 5) {//Picture of Mom
			std::cout << "Used photo of mother" << std::endl;
			int randDamage = 6 + rand() % 4;
			int damage = getSmarts() + getSeduction() + randDamage;
			target->setHealth(target->getHealth() - damage);
			std::cout << "You showed a piture" << getName() << " a picture of their mom." << target->getName() << " for " << damage << "damage." << std::endl;
		}

		else if (id == 6) { // basic health potion 
			std::cout << "Used basic health potion" << std::endl;
			int randHealing = 1 + rand() % 3;
			int hlth = randHealing;
			if ((getHealth() + hlth) > getMaxHealth()) {
				setHealth(getMaxHealth());
				std::cout << "You healed." << std::endl;
			}
			else {
				setHealth(getHealth() + hlth);
				std::cout << "You healed for " << hlth << "damage." << std::endl;
			}
		}

		else if (id == 7) { // medium health potion 
			std::cout << "Used medium health potion" << std::endl;
			int randHealing = 4 + rand() % 4;
			int hlth = randHealing;
			if ((getHealth() + hlth) > getMaxHealth()) {
				setHealth(getMaxHealth());
				std::cout << "You healed." << std::endl;
			}
			else {
				setHealth(getHealth() + hlth);
				std::cout << "You healed for " << hlth << "damage." << std::endl;
			}
		}
		
		else if (id == 8) { // max health potion 
			std::cout << "Used max health potion." << std::endl;
			setHealth(getMaxHealth());
		}

		else if (id == 9) {//Math test
			std::cout << "Used math test" << std::endl;
			int damage = target->getSmarts();
			target->setHealth(target->getHealth() - damage);
			std::cout << "You gave a math test to" << target->getName() << " for " << damage << "damage." << std::endl;
		}

		else if (id == 10) {//Love Potion
			std::cout << "Used math test" << std::endl;
			int damage = getSeduction();
			target->setHealth(target->getHealth() - damage);
			std::cout << "You attempt to seduce" << target->getName() << " for " << damage << "damage." << std::endl;
			setSeduction(seduction + 1);
		}
	}

	inventory* getInventory() {
		return playerInv;
	}
	void setInventory(inventory* newInv) {
		playerInv = newInv;
	}
};
