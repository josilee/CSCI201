#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Structure to hold state information
struct StateInfo {
    string longName;
    string governor;
    string stateFlower;
};

int main() {
    // Map to store state abbreviations with corresponding StateInfo
    map<string, StateInfo> stateMap;

    // Read state information from file
    ifstream inputFile("state_info.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    string abbreviation, longName, governor, stateFlower;

    // Read each line from the file and populate the map
    while (inputFile >> abbreviation >> ws && getline(inputFile, longName) && getline(inputFile, governor) && getline(inputFile, stateFlower)) {
        StateInfo info;
        info.longName = longName;
        info.governor = governor;
        info.stateFlower = stateFlower;

        // Insert into map
        stateMap[abbreviation] = info;
    }

    inputFile.close();

    // Prompt user for state abbreviation
    string userInput;
    cout << "Enter a state abbreviation (or 'quit' to exit): ";
    while (cin >> userInput) {
        // Check if the user wants to quit
        if (userInput == "quit") {
            break;
        }

        // Lookup state information in the map
        auto it = stateMap.find(userInput);
        if (it != stateMap.end()) {
            // State abbreviation found, display information
            cout << "State: " << it->second.longName << endl;
            cout << "Governor: " << it->second.governor << endl;
            cout << "State Flower: " << it->second.stateFlower << endl;
        } else {
            // State abbreviation not found
            cout << "Invalid state abbreviation. Please try again." << endl;
        }

        cout << "Enter a state abbreviation (or 'quit' to exit): ";
    }

    cout << "Exiting program." << endl;

    return 0;
}
