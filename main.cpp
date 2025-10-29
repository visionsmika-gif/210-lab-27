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
    for (map<string, tuple<int, string, string>>::iterator it = vilagerInfo.begin();
                                               it != vilagerInfo.end(); ++it) {
        cout << it->first << " [";
        cout << get<0>(it->second) << ", ";    // Output friendship level
        cout << get<1>(it->second) << ", ";    // Output species
        cout << get<2>(it->second) << "]\n";   // Output catchphrase
    }

    // delete an element
    vilagerInfo.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = vilagerInfo.find(searchKey);
    if (it != vilagerInfo.end()) {  // the iterator points to beyond the end of the map
                                    // if searchKey is not found
        cout << "\nFound " << searchKey << "'s info: [";

        cout << get<0>(it->second) << ", ";    // Output friendship level
        cout << get<1>(it->second) << ", ";    // Output species
        cout << get<2>(it->second) << "]\n";   // Output catchphrase
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << vilagerInfo.size() << endl;
    vilagerInfo.clear();
    cout << "Size after clear: " << vilagerInfo.size() << endl;

    return 0;
}
