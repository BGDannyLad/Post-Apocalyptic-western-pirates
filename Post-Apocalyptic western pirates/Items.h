#pragma once
#include <iostream>




class item {
private:
	item* next;
	item* last;
	int count;
	int itemID;

public:
	int getCount(){
		return count;
	}
	int getID() {
		return itemID;
	}
	item* getNext() {
		return next;
	}
	item* getLast() {
		return last;
	}
	void setCount(int n){
		count = n;
	}
	void setID(int n) {
		itemID = n;
	}
};
