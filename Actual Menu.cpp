// Actual Menu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

void startGame() {
    std::cout << "Starting the game." << std::endl;
}

void corporateCharacter() {
    std::cout << "You have chosen the corporate character." << std::endl;
    // Add corporate character-specific actions or gameplay here
}

void outlawCharacter() {
    std::cout << "You have chosen the outlaw character." << std::endl;
    // Add outlaw character-specific actions or gameplay here
}

void quitGame() {
    std::cout << "Quitting the game." << std::endl;
    exit(0);
}

void displayMenu() {
    std::cout << "\nMain Menu:" << std::endl;
    std::cout << "1. Start Game" << std::endl;
    std::cout << "2. Quit Game" << std::endl;
}

void displayCharacterOptions() {
    std::cout << "\nCharacter Options:" << std::endl;
    std::cout << "1. Corporate" << std::endl;
    std::cout << "2. Outlaw" << std::endl;
}

int main() {
    char choice, characterChoice;

    do {
        displayMenu();
        std::cout << "Enter the number corresponding to your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            startGame();
            displayCharacterOptions();
            std::cout << "Enter the number corresponding to your character choice: ";
            std::cin >> characterChoice;
            switch (characterChoice) {
            case '1':
                corporateCharacter();
                break;
            case '2':
                outlawCharacter();
                break;
            default:
                std::cout << "Invalid character choice. Please enter 1 for Corporate or 2 for Outlaw." << std::endl;
            }
            break;
        case '2':
            quitGame();
            break;
        default:
            std::cout << "Invalid choice. Please enter 1 to Start Game or 2 to Quit Game." << std::endl;
        }

    } while (choice != '2');

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
