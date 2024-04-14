#pragma once
#include "items.h"
class inventory
{
private:
    item* head, * tail, * place;
public:
    inventory()
    {
        item dagger(NULL, NULL, 0,1);
        head = &dagger;
        item wigglyFish(NULL, &dagger, 0, 2);
        tail = &wigglyFish;
        place = &dagger;
    }
    item* search(int key) {
        item* find = head;
        while (find->getNext() != NULL and find->getID() != key) {
            find = find->getNext();
        }
        if (find->getID() == key) {
            return find;
        }
        else {
            return NULL;
        }
    }
    void addItem(int id, int num){
        search(id)->addCount(num);
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
    void display() {
        item* gasgasgas = head;
        while (gasgasgas != NULL) {
            std::cout << "ID: " << gasgasgas->getID() << ", num: " << gasgasgas->getCount() << ", next: " << gasgasgas->getNext() << std::endl;
            if (gasgasgas->getNext() == NULL) {
                std::cout << "End of nodes at slot." << std::endl;
            }
            gasgasgas = gasgasgas->getNext();
        }
    }
    ~inventory() {
        item* current = head;
        while (current != NULL) {
            item* next = current->getNext();
            delete current;
            current = next;
        }
    }
};