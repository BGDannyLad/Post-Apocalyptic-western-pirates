// Outlaw Dialogue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> // For system("pause")

using namespace std;

void fightShipmates() {
    cout << "The shipmates beat you badly." << endl;
    cout << "1. Captain throws you off the ship." << endl;
    cout << "2. Shipmates throw you off the ship." << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "Captain throws you off the ship." << endl;
    }
    else if (choice == 2) {
        cout << "Shipmates throw you off the ship." << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }
}

int main() {
    string captainMsg1 = "Captain: I confront you, outlaw. Do you deny or confess?";
    string deny = "1. Deny";
    string confess = "2. Confess";
    string captainMsg2 = "Captain: I know you are lying. Shipmates, kill him!";
    string captainMsg3 = "Captain: Thank you for being honest with me.";
    string outlawMsg1 = "Outlaw: I won't steal water from you anymore.";
    string captainMsg4 = "Captain: I don't believe you. I am going to throw you overboard.";
    string outlawMsg2 = "Outlaw: I am sorry.";
    string outlawMsg3 = "Outlaw: I do not regret anything I did!";
    string captainMsg5 = "Captain: Well, you should.";

    int choice1, choice2;

    cout << captainMsg1 << endl;
    cout << deny << endl;
    cout << confess << endl;
    cin >> choice1;

    if (choice1 == 1) {
        cout << captainMsg2 << endl;
        cout << "1. Fight shipmates" << endl;
        cout << "2. Jump off boat" << endl;
        cin >> choice2;
        if (choice2 == 1) {
            fightShipmates();
        }
        else if (choice2 == 2) {
            cout << "You jump off the boat." << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
    else if (choice1 == 2) {
        cout << captainMsg3 << endl;
        cout << outlawMsg1 << endl;
        cout << "1. I am sorry" << endl;
        cout << "2. I do not regret anything I did!" << endl;
        cin >> choice2;
        if (choice2 == 1) {
            cout << "Captain makes you walk the plank." << endl;
        }
        else if (choice2 == 2) {
            cout << captainMsg5 << endl;
            cout << "1. I deserve to be the captain" << endl;
            cout << "2. Fight the captain" << endl;
            cin >> choice1;
            if (choice1 == 1) {
                cout << "Captain fights you and throws you off the ship." << endl;
            }
            else if (choice1 == 2) {
                cout << "Captain: Stay off my ship. I hope you run out of water and die in the desert ." << endl;
            }
            else {
                cout << "Invalid choice." << endl;
            }
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
    else {
        cout << "Invalid choice." << endl;
    }

    system("pause"); // For Windows, to keep the console open
    return 0;
}

