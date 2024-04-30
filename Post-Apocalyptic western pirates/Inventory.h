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
        head = new item(nullptr, nullptr, 0, 1, 5, "Half Broken Dagger");//last number is value and second is ID
 tail = new item(nullptr, nullptr, 0, 2, 5, "Dried Fish");
 head->setNext(tail);
 tail->setLast(head);
 place = head;

 item* item3 = new item(nullptr, nullptr, 0, 3, 5, "Cactus Sword");
 item* item4 = new item(nullptr, nullptr, 0, 4, 5, "Blunderbuss");
 item* item5 = new item(nullptr, nullptr, 0, 5, 5, "Picture of Mom");
 item* item6 = new item(nullptr, nullptr, 0, 6, 5, "Basic Health Potion");
 item* item7 = new item(nullptr, nullptr, 0, 7, 5, "Medium Health Potion");
 item* item8 = new item(nullptr, nullptr, 0, 8, 5, "Max Health Potion");
 item* item9 = new item(nullptr, nullptr, 0, 9, 5, "Math Test");

 tail->setNext(item3);
 item3->setLast(tail);
 item3->setNext(item4);
 item4->setLast(item3);
 item4->setNext(item5);
 item5->setLast(item4);
 item5->setNext(item6);
 item6->setLast(item5);
 item6->setNext(item7);
 item7->setLast(item6);
 item7->setNext(item8);
 item8->setLast(item7);
 item8->setNext(item9);
 item9->setLast(item8);
 item9->setNext(head); 
 head->setLast(item9);

 head = item3;
 tail = item9;
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
