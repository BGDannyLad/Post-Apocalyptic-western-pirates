#pragma once
#include "items.h"
class linked_list
{
private:
    item* head, * tail, * place;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
        place = NULL;
    }
    item* search(int key) {
        item* find = head;
        while (find->getNext() != NULL and find->getKey() != key) {
            find = find->getNext();
        }
        if (find->getKey() == key) {
            return find;
        }
        else {
            return NULL;
        }
    }
    void push_back(item* nodude, int n)
    {
        nodude->setData(n);
        nodude->setNext(NULL);

        if (head == NULL)
        {
            place = nodude;
            head = nodude;
            tail = nodude;
            nodude->setLast(NULL);
        }
        else
        {
            tail->setNext(nodude);
            nodude->setLast(tail);
            tail = tail->getNext();
            tail->setNext(NULL);
            place = head;
        }
    }
    item* getCurrent() {
        return place;
    }
    item* getTail() {
        return tail;
    }
    item* getFirst() {
        return head;
    }
    void pushFront(item* front, int n) {
        head->setLast(front);
        front->setNext(head);
        front->setData(n);
        head = front;
        front->setLast(NULL);
        place = front;
    }
    item* deleteAt(item* current) {
        place = current;
        if (place == tail) {
            item* temp = tail->getLast();
            item* oldTail = tail;
            tail = temp;
            tail->setNext(NULL);
            place = tail;
            return oldTail;
        }
        else if (place == head) {
            item* temp = head->getNext();
            item* oldHead = head;
            temp->setLast(NULL);
            head = temp;
            place = head;
            return oldHead;
        }
        else {
            item* del = place;
            item* prev = place->getLast();
            place = place->getNext();
            prev->setNext(place);
            place->setLast(prev);
            return del;
        }
    }
    item* pop_back() {
        item* oldTail = tail;
        item* nwTail = tail->getLast();
        tail = nwTail;
        tail->setNext(NULL);
        place = tail;
        return oldTail;
    }
    item* pop_front() {
        item* oldHead = head;
        item* nwHead = head->getNext();
        head = nwHead;
        nwHead->setLast(NULL);
        return oldHead;
        place = nwHead;
    }
    void display() {
        item* gasgasgas = head;
        while (gasgasgas != NULL) {
            cout << "Data: " << gasgasgas->getData() << ", key: " << gasgasgas->getKey() << ", next: " << gasgasgas->getNext() << endl;
            if (gasgasgas->getNext() == NULL) {
                cout << "End of nodes at slot." << endl;
            }
            gasgasgas = gasgasgas->getNext();
        }
    }
    ~linked_list() {
        item* current = head;
        while (current != NULL) {
            item* next = current->getNext();
            delete current;
            current = next;
        }
    }
};

class inv {
private:
	item* weapon;
	item* secondary;
	item* Potion;
	item* Passive;
public:
	void setWeapon(item* wepawn) {
		weapon = wepawn;
	}
	void setSecondary(item* segond) {
		secondary = segond;
	}
	void setPotion(item* wepawn) {

	}
	void additem(int id, int index) {

	}

};