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
	void setNext(item* nxt) {
		next = nxt;
	}
	item* getLast() {
		return last;
	}
	void setLast(item* lst) {
		last = lst;
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
	

};
//1 is basic dagger for now
//2 is wobbly fish