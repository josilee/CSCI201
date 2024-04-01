/*
Author: Josiah Davis
Program name: main.cpp
Purpose: Displays dimensions and color of a cube
Date: 03/25/2024
*/

#include <limits>
#include <limits>
#include <iostream>
#include <string>

using namespace std;

// Cube class definition
class Cube {
private:
    int length;
    int width;
    int height;
    string color;

public:
    // Constructor
    Cube(int len, int wid, int hei, string col) : length(len), width(wid), height(hei), color(col) {}

    // Accessor methods
    int getLength() const { return length; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    string getColor() const { return color; }

    // Mutator methods
    void setLength(int len) { length = len; }
    void setWidth(int wid) { width = wid; }
    void setHeight(int hei) { height = hei; }
    void setColor(string col) { color = col; }

    // Method to calculate volume
    int calculateVolume() const { return length * width * height; }
};

// Function to validate user input for dimensions and color
int validateDimensionInput() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail() || input <= 0) {
            cout << "Invalid input, please enter a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return input;
}

string validateColorInput() {
    string input;
    // Assuming color validation is basic, just check it's not empty.
    while (true) {
        cin >> input;
        if (input.empty()) {
            cout << "Invalid input, please enter a non-empty string for color: ";
        } else {
            break;
        }
    }
    return input;
}

int main() {
    // Prompt user for cube details
    cout << "Enter the length of the cube: ";
    int length = validateDimensionInput();

    cout << "Enter the width of the cube: ";
    int width = validateDimensionInput();

    cout << "Enter the height of the cube: ";
    int height = validateDimensionInput();

    cout << "Enter the color of the cube: ";
    string color = validateColorInput();

    // Create Cube object
    Cube myCube(length, width, height, color);

    // Display initial cube details
    cout << "\nInitial cube details:" << endl;
    cout << "Length: " << myCube.getLength() << ", Width: " << myCube.getWidth();
    cout << ", Height: " << myCube.getHeight() << ", Color: " << myCube.getColor();
    cout << ", Volume: " << myCube.calculateVolume() << endl;

    // Prompt user to change cube details
    cout << "\nTo modify cube details:" << endl;
    
    cout << "Enter new length: ";
    myCube.setLength(validateDimensionInput());
    
    cout << "Enter new width: ";
    myCube.setWidth(validateDimensionInput());
    
    cout << "Enter new height: ";
    myCube.setHeight(validateDimensionInput());
    
    cout << "Enter new color: ";
    myCube.setColor(validateColorInput());

    // Display modified cube details
    cout << "\nModified cube details:" << endl;
    cout << "Length: " << myCube.getLength() << ", Width: " << myCube.getWidth();
    cout << ", Height: " << myCube.getHeight() << ", Color: " << myCube.getColor();
    cout << ", Volume: " << myCube.calculateVolume() << endl;

    return 0;
}
