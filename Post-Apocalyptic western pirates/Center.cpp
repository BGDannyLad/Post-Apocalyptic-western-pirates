#include <iostream>
#include "Items.h"
#include "Inventory.h"
#include "Player.h"
#include "Menu.h"
using namespace std;

int main() {
	openMenu(0);
	inventory test;
	Player playa(2000, 1000000, 1000, 100, 999999, 20, 0, &test);
	playa.getInventory()->display();
	playa.getInventory()->addItem(1, 1);
	playa.getInventory()->display();
	playa.getInventory()->addItem(2, 10);
	
	cout << "Current hand: " << playa.getHand()->getID() << endl;
	playa.useHand(NULL);
	playa.changeHand(2);
	cout << "Current hand: " << playa.getHand()->getID() << endl;
	playa.useHand(NULL);
}