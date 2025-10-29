#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // The map's value has been modified to a tuple with a friendship level (int), species (string), and catchphrase (string).
    map<string, tuple<int, string, string>> vilagerInfo;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    vilagerInfo["Audie"] = {0, "Wolf", "Foxtrot"};
    vilagerInfo["Raymond"] = {0, "Cat", "Crisp"};
    vilagerInfo.insert({"Marshal", {0, "Squirrel", "Sulky"}});

    // access the map using a range-based for loop
    cout << "Villager details:" << endl;
    for (auto pair : vilagerInfo) {
        cout << pair.first << " [";             // Output villager name
        cout << get<0>(pair.second) << ", ";    // Output friendship level
        cout << get<1>(pair.second) << ", ";    // Output species
        cout << get<2>(pair.second) << "]\n";   // Output catchphrase
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = vilagerInfo.begin();
                                               it != vilagerInfo.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
