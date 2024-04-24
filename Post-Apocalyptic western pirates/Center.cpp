#include <iostream>
#include "Items.h"
#include "Inventory.h"
#include "Player.h"
#include "Menu.h"
#include "IntroScene.h"
using namespace std;

int main() {
	inventory test;
	//Player(int muscles, int intelligence, int dex, int attractiveness, int mony, int typ, int maxH,string nme, inventory* inv) {
	Player playa(200, 1000000, 1000, 100, 999999, 20, 0, 2000, &test);
	if (openMenu(1) == 1) {
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
	playa.useHand(NULL);
}