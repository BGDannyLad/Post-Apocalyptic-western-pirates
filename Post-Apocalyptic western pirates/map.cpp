#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Map {
private:
    unordered_map<int, string> locations;

public:
    Map() {
        // Initialize the locations
        locations[1] = "Pirate";
        locations[2] = "Corporate";
        locations[3] = "Aliens Ship";
        locations[4] = "Desert";
    }

    void displayLocations() {
        cout << "Choose your destination:" << endl;
        for (const auto& pair : locations) {
            cout << pair.first << ". " << pair.second << endl;
        }
    }

    bool isValidDestination(int choice) {
        return locations.find(choice) != locations.end();
    }

    string getLocationName(int choice) {
        return locations[choice];
    }
};

int main() {
    Map map;

    // Display available locations
    map.displayLocations();

    int choice;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    if (map.isValidDestination(choice)) {
        string destination = map.getLocationName(choice);
        cout << "You are traveling to: " << destination << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

