
#pragma once
#include <iostream>
#include <string>
class item {
private:
	item* next;
	int count;
	int itemID;
	int money;
	std::string itemName;
	int type;
public:
	item(item* nxt, int cnt, int id, int value, int typ, std::string name) {
		next = nxt;
		count = cnt;
		itemID = id;
		money = value;
		itemName = name;
		type = typ;
	}
	void setType(int n) {
		type = n;
	}
	int getType() {
		return type;
	}
	std::string getItemName() {
		return itemName;
	}
	void setItemName(std::string nme) {
		itemName = nme;
	}
	int getCount() {
		return count;
	}
	int getID() {
		return itemID;
	}
	item* getNext() {
		return next;
	}
	void setNext(item* nxt) {
		next = nxt;
	}
	void setCount(int n) {
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
	int getValue() {
		return money;
	}
	void setValue(int val) {
		money = val;
	}


};
//1 is basic dagger for now
//2 is wobbly fish