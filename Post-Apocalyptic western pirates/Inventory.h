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
        head = new item(nullptr, 0, 1, 5, 1, "Half broken dagger");//third number is the value
        tail = new item(nullptr, 0, 2, 5, 1, "Dried Fish");
        head->setNext(tail);
        place = head;
        tail->setNext(new item(nullptr, 0, 3, 5, 1, "Cactus Sword"));
        tail = tail->getNext();

        tail->setNext(new item(nullptr, 0, 4, 5, 1, "Blunderbuss"));
        tail = tail->getNext();

        tail->setNext(new item(nullptr, 0, 5, 5, 1, "Picture of Mom"));
        tail = tail->getNext();

        tail->setNext(new item(nullptr, 0, 6, 5, 2, "Basic Health Potion"));
        tail = tail->getNext();

        tail->setNext(new item( nullptr, 0, 7, 5, 2, "Medium Health Potion"));
        tail = tail->getNext();

        tail->setNext(new item( nullptr, 0, 8, 5, 2, "Max Health Potion"));
        tail = tail->getNext();

        tail->setNext(new item( nullptr, 0, 9, 5, 1, "Math Test"));
        tail = tail->getNext();

        tail->setNext(new item(nullptr, 0, 10, 5, 2, "Love Potion"));
        tail = tail->getNext();
        tail->setNext(NULL);

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
    void addItem(int id, int num) {
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
    item* searchType(int typ) {
        item* find = head;
        while (find->getNext() != NULL and find->getType() != typ) {
            find = find->getNext();
        }
        if (find->getType() == typ) {
            return find;
        }
        else {
            return NULL;
        }
    }
};