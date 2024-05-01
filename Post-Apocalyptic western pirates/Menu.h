#include <iostream>

// Enum to represent character types
enum CharacterType {
    None,
    Corporate,
    Outlaw
};

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

CharacterType openMenu(int startup) {
    if (startup == 1) {
        char choice;
        char characterChoice;
        do {
            displayMenu();
            std::cout << "Enter the number corresponding to your choice: ";
            std::cin >> choice;

            switch (choice) {
            case '1':
                startGame();
                do {
                    displayCharacterOptions();
                    std::cout << "Enter the number corresponding to your character choice: ";
                    std::cin >> characterChoice;
                    switch (characterChoice) {
                    case '1':
                        corporateCharacter();
                        return Corporate; // Return Corporate character type
                    case '2':
                        outlawCharacter();
                        return Outlaw; // Return Outlaw character type
                    default:
                        std::cout << "Invalid character choice. Please enter 1 for Corporate or 2 for Outlaw." << std::endl;
                    }
                } while (characterChoice != '2' && characterChoice != '1');
                break;
            case '2':
                quitGame();
                break;
            default:
                std::cout << "Invalid choice. Please enter 1 to Start Game or 2 to Quit Game." << std::endl;
            }

        } while (choice != '1');
        return None; // If no character type is chosen
    }
    return None; // If startup is not 1
}