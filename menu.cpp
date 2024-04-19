#include <iostream>

void returntogame() {
    std::cout << "Returning to the game" << std::endl;
}

void enterBattle() {
    std::cout << "Entering battle sequence." << std::endl;
}

void manageInventory() {
    std::cout << "Managing inventory." << std::endl;
}

void enterShop() {
    std::cout << "Entering the in-game shop." << std::endl;
}

void chat() {
    std::cout << "Talking to someone." << std::endl;
}

void quitGame() {
    std::cout << "Quitting the game." << std::endl;
    exit(0);
}

void displayMenu() {
    std::cout << "\nGame Menu:" << std::endl;
    std::cout << "1. Return to Game" << std::endl;
    std::cout << "2. Enter Battle" << std::endl;
    std::cout << "3. Manage Inventory" << std::endl;
    std::cout << "4. Enter Shop" << std::endl;
    std::cout << "5. Talk to Someone" << std::endl;
    std::cout << "6. Quit Game" << std::endl;
}

int main() {
    char choice;

    do {
        displayMenu();
        std::cout << "Enter the number corresponding to your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            returntogame();
            break;
        case '2':
            enterBattle();
            break;
        case '3':
            manageInventory();
            break;
        case '4':
            enterShop();
            break;
        case '5':
            chat();
            break;
        case '6':
            quitGame();
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
        }

    } while (choice != '6');

    return 0;
}
