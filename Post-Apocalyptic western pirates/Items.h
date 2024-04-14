#pragma once
#include <iostream>




class item {
private:
	int weight;
	int count;
	int itemID;

public:
	int getCount(){
		return count;
	}
	int getWeight() {
		return weight;
	}
	int getID() {
		return itemID;
	}
};
