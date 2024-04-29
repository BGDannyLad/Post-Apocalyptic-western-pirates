#pragma once
#include "items.h"
class inventory
{
private:
    item* head;
    item* tail;
    item* place;
public:
    inventory()
    {
        head = new item(nullptr, nullptr, 0, 1, 5);//last number is value
        tail = new item(nullptr, nullptr, 0, 2, 5);
        head->setNext(tail);
        tail->setLast(head);
        place = head;
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
        place = search(id);
    }


    item* getCurrent() {
        return place;
    }
    void setCurrent(item* cur) {
        place = cur;
    }
    item* getTail() {
        return tail;
    }
    item* getFirst() {
        return head;
    }
    void display() {
        item* gasgasgas = head;
        while (gasgasgas != nullptr) {
            if (gasgasgas->getCount() > 0) {
                if (gasgasgas == getCurrent()) {
                    std::cout << "You have " << gasgasgas->getCount() << " of " << gasgasgas->getItemName() << ", id of " << gasgasgas->getID() << ", current hand." << std::endl;
                }
                else {
                    std::cout << "You have " << gasgasgas->getCount() << " of " << gasgasgas->getItemName() << ", id of " << gasgasgas->getID() << std::endl;

                }
            }
            gasgasgas = gasgasgas->getNext();
        }
        
    }
    void changeHand(int id) {
        item* target = search(id);
        if (target == nullptr) {
            std::cout << "Invalid id." << std::endl;
        }
        else if (target->getCount() > 0) {
            setCurrent(target);
            std::cout << "Changed hand to " << target->getItemName() << std::endl;
        }
        else {
            std::cout << "You have none of this item." << std::endl;
        }
    }
    ~inventory()
    {
        // Release memory allocated for each item in the inventory
        item* current = head;
        while (current != nullptr)
        {
            item* next = current->getNext(); // Store next pointer before deleting current
            delete current; // Delete the current item
            current = next; // Move to the next item
        }
        // Set pointers to nullptr to avoid dangling pointers
        head = nullptr;
        tail = nullptr;
        place = nullptr;
    }
};