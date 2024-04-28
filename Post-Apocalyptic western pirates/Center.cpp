#include <iostream>
#include "Items.h"
#include "Inventory.h"
#include "Player.h"
#include "Menu.h"
#include "IntroScene.h"
#include "Battle.h"
#include "Outlaw Start.h"
using namespace std;

int main() {
	inventory test;
	//Player(int muscles, int intelligence, int dex, int attractiveness, int mony, int maxH, string nme, inventory * inv) {
	Player playa(200, 1000000, 1000, 100, 999999, 20, "Jorje", &test);
	/*if (openMenu(1) == 1) {
		playa.getInventory()->addItem(1, 1);
	}
	else {
		playa.getInventory()->addItem(2, 10);
	}
	CutScreen a;
    a.intro1();
    a.intro2();
    a.intro3();
    a.Shipwave();
	playa.getInventory()->display();
	cout << "Current hand: " << playa.getHand()->getID() << endl;
	playa.useHand(NULL);
	playa.changeHand(1);
	cout << "Current hand: " << playa.getHand()->getID() << endl;
	playa.useHand(NULL);*/
	battle malta(&playa, 4, 2, 5);
	malta.battleInfo();
	run();
}//    battle(Player* plaa, int numEnems, int enemyTyp, int nemyLvl)