#pragma once
#include "Player.h"
#include <iostream>
#include "Inventory.h"
#include <string>
#include "Enemy.h"
using namespace std;
#include<cstdlib>
#include <string.h>
#include "Items.h"

//strength, smarts, dexterity, type, maxHealth;
Enemy* generateEnemy(int type, int lvl) {
    const char* enemy1Names[10] = { "Salty Sam", "Blackeyed Willy", "Dehydrake longnails", "Arineus Seascout", "Big time bobby", "Little time lester", "Sally one-limb", "Johnney no-limb", "Perry plat-y-plus", "Grandma Noteeth" }; //pirates
    const char* enemy2Names[10] = { "Gratinspak Dugelov", "Nikolai Nikitich Ivanov", "Svetlana Pavlovna Orlovsky", "Boris Alexandrovich Kuznetsov", "Anastasia Dmitriyevna Sokolova", "Mikhail Petrovich Romanov", "Yelena Ivanovna Smirnova", "Ekaterina Sergeyevna Petrova", "Igor Sergeyevich Petrov", "Pavel Nikolayevich Orlov" }; //corporate
    const char* enemy3Names[10] = { "Just a lil guy", "Smol", "Shawty", "Plum", "Squeezh", "pum", "blinky", "yug burtman", "a literal jawa", "wampa" }; //alien

    int randName = 0;
    string name;
    int strength;//base stats
    int dexterity = 0;
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
    things->addItem(2, 1);
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
        getFirst()->setLast(getTail());
        getTail()->setNext(getFirst());
    }
    Enemy* deleteAt(Enemy* current) {
        if (current == tail) {
            Enemy* temp = tail->getLast();
            Enemy* oldTail = tail;
            tail = temp;
            tail->setNext(NULL);
            turn = tail;
            getFirst()->setLast(getTail());
            getTail()->setNext(getFirst());
            return oldTail;
        }
        else if (current == head) {
            Enemy* temp = head->getNext();
            Enemy* oldHead = head;
            temp->setLast(NULL);
            head = temp;
            turn = head;
            getFirst()->setLast(getTail());
            getTail()->setNext(getFirst());
            return oldHead;
        }
        else {
            Enemy* del = current;
            Enemy* prev = current->getLast();
            current = current->getNext();
            prev->setNext(current);
            current->setLast(prev);
            return del;
        }
    }
    Enemy* pop_back() {
        Enemy* oldTail = tail;
        Enemy* nwTail = tail->getLast();
        tail = nwTail;
        tail->setNext(NULL);
        turn = tail;
        getFirst()->setLast(getTail());
        getTail()->setNext(getFirst());
        return oldTail;

    }
    Enemy* pop_front() {
        Enemy* oldHead = head;
        Enemy* nwHead = head->getNext();
        head = nwHead;
        nwHead->setLast(NULL);
        turn = nwHead;
        getFirst()->setLast(getTail());
        getTail()->setNext(getFirst());
        return oldHead;

    }
    void battleInfo() {
        Enemy* gasgasgas = head->getNext();
        int i = 0;
        while (gasgasgas != head) {
            std::cout << "(" << i << ")";
            gasgasgas->displayStuff();
            gasgasgas = gasgasgas->getNext();
            i++;
        }
    }
    void setNumEnemies(int anemone) {
        numEnemies = anemone;
    }
    int getNumEnemies() {
        return numEnemies;
    }
    battle(Player* plaa, int numEnems, int enemyTyp, int nemyLvl)
    {
        srand((unsigned)time(NULL));
        head = NULL;
        tail = NULL;
        turn = NULL;
        numEnemies = numEnems;
        for (int i = 0; i < numEnems; i++) {
            push_back(generateEnemy(enemyTyp, nemyLvl));
        }
        playa = plaa;
        pushFront(new Enemy(playa->getStrength(), playa->getSmarts(), playa->getDexterity(), 0, playa->getMaxHealth(), playa->getName(), playa->getInventory()));
        getFirst()->setLast(getTail());
        getTail()->setNext(getFirst());
    }//int muscles, int intelligence, int dex, int typ, int maxH, string nme, inventory* inv
    //be able to retreat, use item, seduce enemy

    int playerTurn() {//returns 1 if retreated and failed, 2 if successfully retreated, 3 if seduce enemy and fail, 4 if succeed, 5 if use item.
        battleInfo();
        std::cout << "Its your turn!" << std::endl;
        int turn_taken = 0;
        playa->getInventory()->display();
        string i;
        while (turn_taken == 0) {
            i = "";
            std::cout << "You can: \n(1) Use item in hand\n(2) Attempt to Seduce Enemy\n(3)Cowardly Retreat\n(4) View Inventory\n(5) Change Hand\nEnter choice: ";
            std::cin >> i;
            if (i == "1") {
                if (playa->getHand()->getType() == 1) {//for weapon
                    int attack = 0;
                    string target;
                    while (attack == 0) {
                        target = "";
                        std::cout << "Target enemy number 1-" << numEnemies << ": ";
                        cin >> target;
                        if (strspn(target.c_str(), "0123456789") == target.size()) {//test for int
                            int enemyIndex = stoi(target);//convert to int
                            if (enemyIndex > 0 && enemyIndex < numEnemies + 1) {//if the number is an enemy
                                Enemy* search = head;
                                for (int i = 0; i < enemyIndex; i++) {//find the enemy
                                    search = search->getNext();
                                }
                                playa->useHand(search);//attack enemy
                                if (search->getHealth() <= 0) {
                                    std::cout << deleteAt(search)->getName() << " has died." << std::endl;
                                    numEnemies = numEnemies - 1;
                                }
                                attack = 1;
                                return 5;
                            }
                            else {
                                std::cout << "Enter valid index plz.\n";
                            }

                        }
                        else {
                            std::cout << "Enter a number plz\n";
                        }

                    }
                }
                else if (playa->getHand()->getType() == 2) {//for potion
                    playa->useHand(NULL);
                }
            }
            else if (i == "2") {//seduce
                int attack = 0;
                string target;
                while (attack == 0) {
                    target = "";
                    std::cout << "Target enemy number 1-" << numEnemies << ": ";
                    cin >> target;
                    if (strspn(target.c_str(), "0123456789") == target.size()) {//test for int
                        int enemyIndex = stoi(target);//convert to int
                        if (enemyIndex > 0 && enemyIndex < numEnemies + 1) {//if the number is an enemy
                            Enemy* search = head;
                            for (int i = 0; i < enemyIndex; i++) {//find the enemy
                                search = search->getNext();
                            }
                            if (playa->attemptToSeduce(search) == 1) {//if succeeded
                                std::cout << deleteAt(search)->getName() << " has left the battle smitten." << std::endl;
                                numEnemies = numEnemies - 1;
                                return 4;
                            }
                            else {//if failed
                                std::cout << search->getName() << " has resisted your charms." << std::endl;
                                return 3;
                            }
                        }
                        else {
                            std::cout << "Enter valid index plz.\n";
                        }

                    }
                    else {
                        std::cout << "Enter a number plz\n";
                    }

                }
            }
            else if (i == "3") {
                int escapeStat = playa->getDexterity();
                int escape = 2;
                for (int i = 0; i < numEnemies; i++) {
                    int rng = rand() % 20 - escapeStat;
                    if (rng > 8) {
                        escape = 1;
                    }
                }
                if (escape == 2) {
                    std::cout << "Successfully retreated.\n";
                    return 2;
                }
                else {
                    std::cout << "You trip over a rogue spoon in the way of your retreat, rats." << std::endl;
                    return 1;
                }
                return escape;

            }
            else if (i == "4") {
                playa->getInventory()->display();
            }
            else if (i == "5") {
                string id;
                std::cout << "Enter item Id: ";
                std::cin >> id;
                if (strspn(id.c_str(), "0123456789") == id.size()) {
                    playa->getInventory()->changeHand(stoi(id));
                }
            }
            else {
                cout << "nice try buddy.\n";
            }
        }
    }
    //void enemyturn(Enemy* anemony) {
    //    if (anemony->getHealth() <= .25 * anemony->getMaxHealth() && anemony->getInventory()->searchType(2) != NULL) {//If they are low and have heals
    //        anemony->useItem(anemony->getInventory()->searchType(2), NULL);
    //    }
    //    else if (numEnemies == 1 && anemony->getHealth() < .5 * anemony->getMaxHealth()) {//if they are low and are the only enemy left
    //        int escapeStat = anemony->getDexterity();
    //        int escape = 2;
    //        int rng = rand() % 20 - escapeStat + playa->getStrength();
    //        if (rng > 8) {
    //            escape = 1;
    //        }
    //        if (escape == 2) {
    //            std::cout << anemony->getName() << " retreated.\n";
    //            numEnemies = numEnemies - 1;
    //        }
    //        else {
    //            std::cout << anemony->getName() << " attempted to retreat but you dragged them back" << std::endl;
    //        }
    //    }
    //    else {
    //        item* weapon = anemony->getInventory()->searchType(1);
    //        anemony->useItem(weapon, playa);
    //    }
    //}
    void startBattleLoop() {
        while (playa->getHealth() > 0 && getNumEnemies() > 0) {
            if (turn->getType() == 0) { //if its the player's turn
                playerTurn();
            }
            /*else {
                enemyturn(turn);
            }
            turn = turn->getNext();*/
        }
    }
};