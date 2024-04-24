#pragma once
#include "Player.h"
#include <iostream>
#include "Inventory.h"
#include <string>
using namespace std;
#include<cstdlib>


Player* generateEnemy(int type, int lvl) {
    const char* enemy1Names[10] = { "Salty Sam", "Blackeyed Willy", "Dehydrake longnails", "Arineus Seascout", "Big time bobby", "Little time lester", "Sally one-limb", "Johnney no-limb", "Perry plat-y-plus", "Grandma Noteeth"}; //pirates
    const char* enemy2Names[10] = { "Gratinspak Dugelov", "Nikolai Nikitich Ivanov", "Svetlana Pavlovna Orlovsky", "Boris Alexandrovich Kuznetsov", "Anastasia Dmitriyevna Sokolova", "Mikhail Petrovich Romanov", "Yelena Ivanovna Smirnova", "Ekaterina Sergeyevna Petrova", "Igor Sergeyevich Petrov", "Pavel Nikolayevich Orlov"}; //corporate
    const char* enemy3Names[10] = { "Just a lil guy", "Smol", "Shawty", "Plum", "Squeezh", "pum", "blinky", "yug burtman", "a literal jawa", "wampa"}; //alien
    srand((unsigned)time(NULL));
}
class battle
{
private:
    Player* head, * tail, * turn;
    int numEnemies, enemyType, enemyLvl;
public:
    battle(Player* playa, int numEnems, int enemyTyp, int nemyLvl)
    {
        head = NULL;
        tail = NULL;
        turn = NULL;
    }
    
    void push_back(Player* nodude, int n)
    {
        nodude->setData(n);
        nodude->setNext(NULL);

        if (head == NULL)
        {
            turn = nodude;
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
            turn = head;
        }
    }
    Player* getCurrent() {
        return turn;
    }
    Player* getTail() {
        return tail;
    }
    Player* getFirst() {
        return head;
    }
    void pushFront(Player* front, int n) {
        head->setLast(front);
        front->setNext(head);
        front->setData(n);
        head = front;
        front->setLast(NULL);
        turn = front;
    }
    Player* deleteAt(Player* current) {
        turn = current;
        if (turn == tail) {
            Player* temp = tail->getLast();
            Player* oldTail = tail;
            tail = temp;
            tail->setNext(NULL);
            turn = tail;
            return oldTail;
        }
        else if (turn == head) {
            Player* temp = head->getNext();
            Player* oldHead = head;
            temp->setLast(NULL);
            head = temp;
            turn = head;
            return oldHead;
        }
        else {
            Player* del = turn;
            Player* prev = turn->getLast();
            turn = turn->getNext();
            prev->setNext(turn);
            turn->setLast(prev);
            return del;
        }
    }
    Player* pop_back() {
        Player* oldTail = tail;
        Player* nwTail = tail->getLast();
        tail = nwTail;
        tail->setNext(NULL);
        turn = tail;
        return oldTail;
    }
    Player* pop_front() {
        Player* oldHead = head;
        Player* nwHead = head->getNext();
        head = nwHead;
        nwHead->setLast(NULL);
        return oldHead;
        turn = nwHead;
    }
    void display() {
        Player* gasgasgas = head;
        while (gasgasgas != NULL) {
            cout << "Data: " << gasgasgas->getData() << ", key: " << gasgasgas->getKey() << ", next: " << gasgasgas->getNext() << endl;
            if (gasgasgas->getNext() == NULL) {
                cout << "End of nodes at slot." << endl;
            }
            gasgasgas = gasgasgas->getNext();
        }
    }

};