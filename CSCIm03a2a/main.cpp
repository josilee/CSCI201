#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    // Set to store unique words
    set<string> uniqueWords;

    // File input stream to read words from a text file
    ifstream inputFile("input.txt");

    // Check if the file opened successfully
    if (!inputFile) {
        cerr << "Error: Unable to open the file." << endl;
        return 1; // Return error code
    }

    // Read words from the file and insert into the set
    string word;
    while (inputFile >> word) {
        // Convert word to lowercase (optional, to treat words case-insensitively)
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Insert word into the set (automatically ignores duplicates)
        uniqueWords.insert(word);
    }

    // Close the file
    inputFile.close();

    // Display unique words in ascending order
    cout << "Unique words in ascending order:" << endl;
    for (const auto& uniqueWord : uniqueWords) {
        cout << uniqueWord << endl;
    }

    return 0; // Return success
}
