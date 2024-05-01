#pragma once
#include "Inventory.h"
#include "Items.h"

class store {
private:
	inventory* stock;
	int inflation;

public:
	store(int greed, inventory* stok) {
		inflation = greed;
		stock = stok;
	}

	void addItemsToStock() {
		stock->addItem(1, 10);
		stock->addItem(2, 8);
		stock->addItem(3, 5);
		stock->addItem(4, 5);
		stock->addItem(5, 5);
		stock->addItem(6, 5);
		stock->addItem(7, 5);
		stock->addItem(8, 5);
		stock->addItem(9, 5);
		stock->addItem(10, 5);

	}
	void setStock(inventory* stoc) {
		stock = stoc;

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
