#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

void displayVillagerDetails(const map<string, tuple<int, string, string>>& villagerInfo) {
    cout << "Villager details:" << endl;
    for (auto pair : villagerInfo) {
        cout << pair.first << " [";             // Output villager name
        cout << get<0>(pair.second) << ", ";    // Output friendship level
        cout << get<1>(pair.second) << ", ";    // Output species
        cout << get<2>(pair.second) << "]\n";   // Output catchphrase
    }
    cout << "\n";
}

// Function to display a menu of choices labeled 1-4 to the user.
// Args:    none
// Returns: the the user's choice (an int).
int getUserChoice() {
    int choice;
    cout << "Options:\n";
    cout << "1. Add Villager\n";
    cout << "2. Delete Villager\n";
    cout << "3. Increase Friendship\n";
    cout << "4. Decrease Friendship\n";
    cout << "5. Search for Villager\n";
    cout << "6. Exit\n";
    do {
        cout << "Enter choice --> ";
        cin >> choice;
        if (choice < 1 || choice > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6 (inclusive).";
        }
        cout << "\n";
    } while (choice < 1 || choice > 6);
    return choice;
}

void addVillager(map<string, tuple<int, string, string>>& villagerInfo) {
    string name;
    int level;
    string species;
    string catchphrase;
    
    // Get name
    cout << "Villager name: ";
    getline(cin, name);

    // Get friendship level
    do {
        cout << "Friendship level: ";
        cin >> level;
        if (level < 0 || level > 10) {
            cout << "Invalid friendship level. Please enter a number between 0 and 10 (inclusive).\n";
        }
    } while (level < 0 || level > 10);
    cin.ignore();

    // Get species
    cout << "Species: ";
    getline(cin, species);

    // Get catchphrase
    cout << "Catchphrase: ";
    getline(cin, catchphrase);

    villagerInfo[name] = {level, species, catchphrase};

    cout << name << " added.\n";
}

void deleteVillager(map<string, tuple<int, string, string>>& villagerInfo) {
    string searchKey;
    cout << "Enter the name of the villager you want to delete --> ";
    getline(cin, searchKey);

    auto it = villagerInfo.find(searchKey);
    if (it != villagerInfo.end()) {  // the iterator points to beyond the end of the map if searchKey is not found
        villagerInfo.erase(it);
        cout << searchKey << " deleted.\n";
    }
    else {
        cout << searchKey << " was not found." << endl;
    }
}

void increaseFriendship(map<string, tuple<int, string, string>>& villagerInfo) {
    string searchKey;
    cout << "Enter the name of the villager you want to increase the friendship level of --> ";
    getline(cin, searchKey);

    auto it = villagerInfo.find(searchKey);
    if (it != villagerInfo.end()) {  // the iterator points to beyond the end of the map if searchKey is not found
        int& level = get<0>(it->second);
        if (level < 10) {
            cout << searchKey << "'s friendship level is now " << ++level << ".\n";
        }
        else {
            cout << searchKey << "'s friendship level is already maxed.\n";
        }
    }
    else {
        cout << searchKey << " was not found." << endl;
    }
}

void decreaseFriendship(map<string, tuple<int, string, string>>& villagerInfo) {
    string searchKey;
    cout << "Enter the name of the villager you want to decrease the friendship level of --> ";
    getline(cin, searchKey);

    auto it = villagerInfo.find(searchKey);
    if (it != villagerInfo.end()) {  // the iterator points to beyond the end of the map if searchKey is not found
        int& level = get<0>(it->second);
        if (level > 0) {
            cout << searchKey << "'s friendship level is now " << --level << ".\n";
        }
        else {
            cout << searchKey << "'s friendship level is already at a minimum (0).\n";
        }
    }
    else {
        cout << searchKey << " was not found." << endl;
    }
}

void searchForVillager(map<string, tuple<int, string, string>>& villagerInfo) {
    string searchKey;
    cout << "Enter the name of the villager you want to search for --> ";
    getline(cin, searchKey);

    auto it = villagerInfo.find(searchKey);
    if (it != villagerInfo.end()) {  // the iterator points to beyond the end of the map
        // if searchKey is not found
        cout << "Found " << searchKey << "'s info: [";

        cout << get<0>(it->second) << ", ";    // Output friendship level
        cout << get<1>(it->second) << ", ";    // Output species
        cout << get<2>(it->second) << "]\n";   // Output catchphrase
    }
    else {
        cout << searchKey << " was not found." << endl;
    }
}
int main() {
    // The map's value has been modified to a tuple with a friendship level (int), species (string), and catchphrase (string).
    map<string, tuple<int, string, string>> villagerInfo;

    // Insert starter elements into the map.
    villagerInfo["Audie"] = { 0, "Wolf", "Foxtrot" };
    villagerInfo["Raymond"] = { 0, "Cat", "Crisp" };
    villagerInfo.insert({ "Marshal", {0, "Squirrel", "Sulky"} });

    // Output the menu, allowing the user to choose what to do with the villagers.
    int choice;
    do {
        // Display villager details
        displayVillagerDetails(villagerInfo);

        // Get the user's choice
        choice = getUserChoice();
        cin.ignore();
        
        if (choice == 1) {                      // 1. Add Villager
            addVillager(villagerInfo);
        }
        else if (choice == 2) {                 // 2. Delete Villager
            deleteVillager(villagerInfo);
        }
        else if (choice == 3) {                 // 3. Increase Friendship
            increaseFriendship(villagerInfo);
        }
        else if (choice == 4) {                 // 4. Decrease Friendship
            decreaseFriendship(villagerInfo);
        }
        else if (choice == 5) {                 // 5. Search for Villager
            searchForVillager(villagerInfo);
        }
        cout << "\n";
    } while (choice != 6);                      // 6. Exit

    return 0;
}
