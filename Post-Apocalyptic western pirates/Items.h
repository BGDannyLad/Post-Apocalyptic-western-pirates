#pragma once
#include <iostream>

class item {
private:
	item* next;
	item* last;
	int count;
	int itemID;

public:
	item(item* nxt, item* lst, int cnt, int id) {
		next = nxt;
		last = lst;
		count = cnt;
		itemID = id;
	}
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
	void addCount(int n) {
		if ((count + n) >= 0) {
			count = count + n;
		}
		
	}
	void useitem() {
		if (itemID == 1) {
			std::cout << "Used dagger" << std::endl;
		}
		else if (itemID == 2) {
			std::cout << "used wiggly fish";
		}
	}

};
//1 is basic dagger for now
//2 is wobbly fish