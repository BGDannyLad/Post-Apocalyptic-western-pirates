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
