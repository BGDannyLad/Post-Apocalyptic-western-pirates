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
	Player(int muscles, int intelligence, int dex, int attractiveness, int mony, int maxH, string nme, inventory* inv) {
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
			std::cout << "You stabbed " << target->getName() << " for " << damage << " damage." << std::endl;
		}

		else if (id == 2) {//Dried Fish
			std::cout << "Used dried fish" << std::endl;
			int randDamage = 7;
			int damage = getStrength() + randDamage;
			target->setHealth(target->getHealth() - damage);
			std::cout << "You force fed " << target->getName() << " for " << damage << " damage." << std::endl;
		}

		else if (id == 3) {//Cactus Sword
			std::cout << "Used cactus sword" << std::endl;
			int randDamage = 3 + rand() % 5;
			int damage = getDexterity() + randDamage;
			target->setHealth(target->getHealth() - damage);
			std::cout << "You poked " << target->getName() << " for " << damage << " damage." << std::endl;
		}

		else if (id == 4) {//Blunderbuss
			std::cout << "Used blunderbuss" << std::endl;
			int randDamage = 10;
			int damage = getSmarts() + randDamage;
			target->setHealth(target->getHealth() - damage);
			std::cout << "You aimed and shot " << target->getName() << " for " << damage << " damage." << std::endl;
		}

		else if (id == 5) {//Picture of Mom
			std::cout << "Used photo of mother" << std::endl;
			int randDamage = 6 + rand() % 4;
			int damage = getSmarts() + getSeduction() + randDamage;
			target->setHealth(target->getHealth() - damage);
			std::cout << "You showed " << target->getName() << " a picture of their mom for " << damage << " damage." << std::endl;
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
				std::cout << "You healed for " << hlth << " damage." << std::endl;
			}
			getInventory()->addItem(6, -1);
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
				std::cout << "You healed for " << hlth << " damage." << std::endl;
			}
			getInventory()->addItem(7, -1);
		}

		else if (id == 8) { // max health potion
			std::cout << "Used max health potion." << std::endl;
			setHealth(getMaxHealth());
			getInventory()->addItem(8, -1);
		}

		else if (id == 9) {//Math test
			std::cout << "Used math test" << std::endl;
			int damage = target->getSmarts();
			target->setHealth(target->getHealth() - damage);
			std::cout << "You gave a math test to " << target->getName() << " for " << damage << " damage." << std::endl;
		}

		else if (id == 10) {//Love Potion
			std::cout << "Used math test" << std::endl;
			int damage = getSeduction();
			target->setHealth(target->getHealth() - damage);
			std::cout << "You attempt to seduce " << target->getName() << " for " << damage << " damage." << std::endl;
			setSeduction(seduction + 1);
		}
	}

	inventory* getInventory() {
		return playerInv;
	}
	void setInventory(inventory* newInv) {
		playerInv = newInv;
	}
	int attemptToSeduce(Enemy* target) {
		int enemyResistance = target->getSmarts() + 10;
		int targetSed = rand() % 20 + getSeduction();
		const char* seductionPirate[5] = { "You're a legend of a pirate. Not because of your plunder, but because you stole my heart without firing a single shot.", "Your eyes are deeper than the ocean, darker than the night above the sea and brighter than the sun", "I think i found the booty ive been searching my whole life for", "Arrrrrrrrrrr?", "Do you want to drop anchor in my harbor?" }; //pirates
		const char* seductionCorpo[5] = { "Would you climb the corporate ladder with me?", "Is your name ROI? Because you provide the best returns.", "Are you a boardroom? Because you've got me making executive decisions", "Is your strategy long-term? Because I see a future with you.", "Is your business plan innovative? Because you've certainly disrupted my thoughts" }; //corporate
		const char* seductionAlien[5] = { "Do you believe in love at first abduction, or should I fly by again?", "Are you made of stardust? Because every time I look at you, I feel like I'm lost in the cosmos", "Are you a celestial body? Because you've got me orbiting around you.", "Are you a wormhole? Because you've just warped my sense of space and time.", "Are you an interstellar traveler? Because you've just landed in the center of my galaxy" }; //alien
		const char* pirateResponse[5] = { "well shucks", "What be the meening of this?", "Where did this come from? i was just about to slit yer throat", "Arrrrrgh?", "Do ye know what it is you ask for?" }; //pirates
		const char* corpoResponse[5] = { "I..Ive been alone for so long", "Awww i get it", "What is your proposal?", "I do make the best strategic decisions, this is true.", "Somebody finally realising my efforts for the company! This is incredible." }; //corporate
		const char* alienResponse[5] = { "Dude that like kinda racist bro, not all aliens abduct people, only the weird ones.", "Bro i wish i had stardust, it hits so hard", "My guy, were all celestial bodies.", "Dude you might just have had one too many to drink.", "Well shucks" }; //alien
		const char* seductionPirate2[5] = { "Your deep sunken eye socket calls me to you", "I mean that you're my one and only, my life and my death, my love and my sorrow.", "It comes from the guy that wants to spend the rest of his life with you.", "Ayaaaaaarrrrrgh????!? matey?", "All i know is how i feel. I cant sleep at night when I'm away from you, every waking moment is an eternity of agony when we're apart." }; //pirates
		const char* seductionCorpo2[5] = { "There is no need to go alone any longer, we could be happy together.", "Yeah, you see what i did there? :)", "Marriage. Imagine the tax returns.", "Well make one more, make the decision to live the rest of our lives together.", "I would do more than just that, we could be happy together." }; //corporate
		const char* seductionAlien2[5] = { "Oh.. i didnt know. I mean, the offer still stands?", "Is that an actual thing aliens do? Navermind, you wanna... get married?", "I was doing a bit, we call it a pickup line.", "I have not had any drinks, It is your beauty and the force of your character that compel me to love you.", "Darn right shucks. i would kiss you but were both imaginary videogame characters." }; //alien
		const char* pirateResponseSucceed[5] = { "They do have that effect on people... All right.", "So poetic.. arrgh why not", "Well shucks... im in", "Arrrgh.. ayaaargh :)", "Ye son of a very nice woman, im in." }; //pirates
		const char* corpoResponseSucceed[5] = { "Lonliness is a plague upon me, i hope you may prove to be the cure.", "hehehe yeah :) ok.", "This does make sense from a business perspective, im in.", "Nobody has ever spoken to me this way before, I.. I love you.", "You know what? youre right." }; //corporate
		const char* alienResponseSucceed[5] = { "yeah sure man", "yeah we do that sometimes. I mean sure why not", "Oh.. yeah i think it worked on me", "So elequent, man youre the man.", "dude thats like super existantial, alright, ill spend the rest of my imaginary life with you." }; //alien
		const char* pirateResponseFail[5] = { "They do have that effect on people... but i dont think im ready for this commitment yet.", "Arrrgh your fancy words wont work on me.", "Yer flattery has no harbor in which to lay anchor", "Arrrg.>{", "aye'll remain loyal to me crewmates!" }; //pirates
		const char* corpoResponseFail[5] = { "Lonliness is a plague upon me, and i fear you're not the cure", "I do, but i dont find it funny", "Despite the fact that this makes sense from a business perspective, the happiness of the employees must be considered as well. I dont like you.", "I'm disinclined to acquiesce to your request.", "I think not." }; //corporate
		const char* alienResponseFail[5] = { "Na man, im good", "Yeah we do that sometimes. But na, im kinda chillin over here", "Oh, sorry dude it didnt work on me", "Dude you should like wright books and stuff, but im good for right now.", "Bro thats too philosophical for me man" }; //alien
		int randDialog = rand() % 5;
		if (target->getType() == 1) {
			std::cout << getName() << ": " << seductionPirate[randDialog] << "\n" <<std::endl;
			std::cout << target->getName() << ": " << pirateResponse[randDialog] << "\n" << std::endl;
			std::cout << getName() << ": " << seductionPirate2[randDialog] << "\n" << std::endl;
			if (enemyResistance > targetSed) {//fail
				std::cout << target->getName() << ": " << pirateResponseFail[randDialog] << "\n" << std::endl;
				return 0;
			}
			else {
				std::cout << target->getName() << ": " << pirateResponseSucceed[randDialog] << "\n" << std::endl;
				return 1;
			}
		}
		else if (target->getType() == 2) {//corporate
			std::cout << getName() << ": " << seductionCorpo[randDialog] << "\n" << std::endl;
			std::cout << target->getName() << ": " << corpoResponse[randDialog] << "\n" << std::endl;
			std::cout << getName() << ": " << seductionCorpo2[randDialog] << "\n" << std::endl;
			if (enemyResistance > targetSed) {//fail
				std::cout << target->getName() << ": " << corpoResponseFail[randDialog] << "\n" << std::endl;
				return 0;
			}
			else {
				std::cout << target->getName() << ": " << corpoResponseSucceed[randDialog] << "\n" << std::endl;
				return 1;
			}
		}
		else if (target->getType() == 3) {//alien
			std::cout << getName() << ": " << seductionAlien[randDialog] << "\n" << std::endl;
			std::cout << target->getName() << ": " << alienResponse[randDialog] << "\n" << std::endl;
			std::cout << getName() << ": " << seductionAlien2[randDialog] << "\n" << std::endl;
			if (enemyResistance > targetSed) {//fail
				std::cout << target->getName() << ": " << alienResponseFail[randDialog] << "\n" << std::endl;
				return 0;
			}
			else {
				std::cout << target->getName() << ": " << alienResponseSucceed[randDialog] << "\n" << std::endl;
				return 1;
			}
		}
	}
};