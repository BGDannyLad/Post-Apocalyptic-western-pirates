#pragma once
#include "Player.h"
#include <iostream>
#include "Inventory.h"
#include <string>
#include "Enemy.h"
using namespace std;
#include<cstdlib>

//strength, smarts, dexterity, type, maxHealth;
Enemy* generateEnemy(int type, int lvl) {
    const char* enemy1Names[10] = { "Salty Sam", "Blackeyed Willy", "Dehydrake longnails", "Arineus Seascout", "Big time bobby", "Little time lester", "Sally one-limb", "Johnney no-limb", "Perry plat-y-plus", "Grandma Noteeth"}; //pirates
    const char* enemy2Names[10] = { "Gratinspak Dugelov", "Nikolai Nikitich Ivanov", "Svetlana Pavlovna Orlovsky", "Boris Alexandrovich Kuznetsov", "Anastasia Dmitriyevna Sokolova", "Mikhail Petrovich Romanov", "Yelena Ivanovna Smirnova", "Ekaterina Sergeyevna Petrova", "Igor Sergeyevich Petrov", "Pavel Nikolayevich Orlov"}; //corporate
    const char* enemy3Names[10] = { "Just a lil guy", "Smol", "Shawty", "Plum", "Squeezh", "pum", "blinky", "yug burtman", "a literal jawa", "wampa"}; //alien
    
    int randName = 0;
    string name;
    int strength;//base stats
    int dexterity =0;
    int intelligence = 0;
    int maxHealth = 0;
    int baseStat = lvl;
    if (type == 1) {//pirates
        randName = (rand() % 10);
        name = enemy1Names[randName];
        strength = 4;//base stats
        dexterity = 2;
        intelligence = 1;
        maxHealth;
        for (int i = 0; i < lvl + 1; i++) {
            int randhealth = (rand() % 10);
            maxHealth = maxHealth + randhealth;
        }
        strength = strength + lvl;
        dexterity = dexterity + lvl;
        intelligence = intelligence + lvl;
    }
    else if (type == 2) {//corporate
        randName = (rand() % 10);
        name = enemy2Names[randName];
        strength = 2;//base stats
        dexterity = 1;
        intelligence = 4;
        maxHealth;
        for (int i = 0; i < lvl + 1; i++) {
            int randhealth = (rand() % 10);
            maxHealth = maxHealth + randhealth;

        }
        strength = strength + lvl;
        dexterity = dexterity + lvl;
        intelligence = intelligence + lvl;
    }
    else {//alien
        randName = (rand() % 10);
        name = enemy3Names[randName];
        strength = 4;//base stats
        dexterity = 2;
        intelligence = 1;
        maxHealth;
        for (int i = 0; i < lvl + 1; i++) {
            int randhealth = (rand() % 10);
            maxHealth = maxHealth + randhealth;
        }
        strength = strength + lvl;
        dexterity = dexterity + lvl;
        intelligence = intelligence + lvl;
    }
    inventory* things = new inventory();
    //add code to generate random inventories based on type and level
    things->addItem(1, 1);
    Enemy* averageJoe = new Enemy(strength, intelligence, dexterity, type, maxHealth, name, things);
    return averageJoe;
}
//Enemy(int muscles, int intelligence, int dex, int mony, int typ, int maxH, string nme, inventory* inv)
class battle
{
private:
    Player* playa;
    Enemy* head, * tail, * turn;
    int numEnemies, enemyType, enemyLvl;
public:
    
    
    void push_back(Enemy* nodude)
    {
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
    Enemy* getCurrent() {
        return turn;
    }
    Enemy* getTail() {
        return tail;
    }
    Enemy* getFirst() {
        return head;
    }
    void pushFront(Enemy* front) {
        head->setLast(front);
        front->setNext(head);
        head = front;
        front->setLast(NULL);
        turn = front;
    }
    Enemy* deleteAt(Enemy* current) {
        turn = current;
        if (turn == tail) {
            Enemy* temp = tail->getLast();
            Enemy* oldTail = tail;
            tail = temp;
            tail->setNext(NULL);
            turn = tail;
            return oldTail;
        }
        else if (turn == head) {
            Enemy* temp = head->getNext();
            Enemy* oldHead = head;
            temp->setLast(NULL);
            head = temp;
            turn = head;
            return oldHead;
        }
        else {
            Enemy* del = turn;
            Enemy* prev = turn->getLast();
            turn = turn->getNext();
            prev->setNext(turn);
            turn->setLast(prev);
            return del;
        }
    }
    Enemy* pop_back() {
        Enemy* oldTail = tail;
        Enemy* nwTail = tail->getLast();
        tail = nwTail;
        tail->setNext(NULL);
        turn = tail;
        return oldTail;
    }
    Enemy* pop_front() {
        Enemy* oldHead = head;
        Enemy* nwHead = head->getNext();
        head = nwHead;
        nwHead->setLast(NULL);
        return oldHead;
        turn = nwHead;
    }
    void battleInfo() {
        Enemy* gasgasgas = head;
        while (gasgasgas != NULL) {
            gasgasgas->displayStuff();
            if (gasgasgas->getNext() == NULL) {
                cout << "End of nodes at slot." << endl;
            }
            gasgasgas = gasgasgas->getNext();
        }
    }
    battle(Player* plaa, int numEnems, int enemyTyp, int nemyLvl)
    {
        srand((unsigned)time(NULL));
        head = NULL;
        tail = NULL;
        turn = NULL;
        for (int i = 0; i < numEnems + 1; i++) {
            push_back(generateEnemy(enemyTyp, nemyLvl));
        }
        playa = plaa;
    }
};