#pragma once
#include "Inventory.h"
#include "Items.h"
#include <unordered_map> // for items to have IDs
class store {
private: 
	inventory* stock;
	int inflation;
std::unordered_map<int, Item> availableItems; //map store available items with IDs

public:
	store(int greed, inventory* stok) {
		inflation = greed;
		stock = stok;
	}
	void setStock(inventory* stoc) {
		stock = stoc;
		//Populate availableItems with items
		availableItems[1]=Items("Half Broken Dagger", 1);
		availableItems[2]=Items("Dried Fish", 2);
		availableItems[3]=Items("Cactus Sword", 3);
		availableItems[4]=Items("Blunderbuss", 4);
		availableItems[5]=Items("Picture of Mom", 5);
		availableItems[6]=Items("Basic Health Potion", 6);
		availableItems[7]=Items("Medium Health Potion", 7);
		availableItems[8]=Items("Max Health Potion", 8);
		availableItems[9]=Items("Math Test", 9);
	}
	void setInflation(int infl) {
		inflation = infl;
	}
	inventory* getInventory() {
		return stock;
	}
	int getInflation() {
		return inflation;
	}

};
