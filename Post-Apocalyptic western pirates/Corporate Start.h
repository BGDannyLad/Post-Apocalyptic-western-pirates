#pragma once
#include <iostream> 
#include <cstdlib> // For system("pause")
using namespace std;

void confess() {
    cout << "Thank you. I'm calling security." << endl;
    cout << "Security shows up." << endl;
    cout << "1. Punch security and run" << endl;
    cout << "2. Jump out the window and run" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "You punched security, but they caught you. They are taking you away." << endl;
        cout << "You find yourself dropped off in the desert." << endl;
    }
    else if (choice == 2) {
        cout << "You jumped out the window and ran, but security caught you. They are taking you away." << endl;
        cout << "You find yourself dropped off in the desert." << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }
}

void beConfused() {
    cout << "I have heard that you have been stealing from us." << endl;
    cout << "Security comes in." << endl;
    cout << "1. Punch security and run" << endl;
    cout << "2. Jump out the window and run" << endl;
    int choice;
    cin >> choice;
    if (choice == 1 || choice == 2) {
        cout << "Security caught you as you tried to escape. They are taking you away." << endl;
        cout << "You find yourself dropped off in the desert." << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }
}

int run() {
    string bossMsg1 = "Boss: Can I speak with you?";
    string bossMsg2 = "Boss: I've been informed that you have been stealing from us";
    string listen = "1. Listen";
    string remainSilent = "2. Remain silent";
    string confessChoice = "1. Confess";
    string beConfusedChoice = "2. Be confused";
    string invalidChoice = "Invalid choice.";

    int choice1, choice2;

    cout << bossMsg1 << endl;
    cout << listen << endl;
    cout << remainSilent << endl;
    cin >> choice1;

    if (choice1 == 1) {
        cout << bossMsg2 << endl;
        cout << confessChoice << endl;
        cout << beConfusedChoice << endl;
        cin >> choice2;

        if (choice2 == 1) {
            confess();
        }
        else if (choice2 == 2) {
            beConfused();
        }
        else {
            cout << invalidChoice << endl;
        }
    }
    else if (choice1 == 2) {
        cout << bossMsg2 << endl;
        cout << confessChoice << endl;
        cout << beConfusedChoice << endl;
        cin >> choice2;

        if (choice2 == 1) {
            confess();
        }
        else if (choice2 == 2) {
            beConfused();
        }
        else {
            cout << invalidChoice << endl;
        }
    }
    else {
        cout << invalidChoice << endl;
    }

    system("pause"); // For Windows, to keep the console open
    return 0;
}