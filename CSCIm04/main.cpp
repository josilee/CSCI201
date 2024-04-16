#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Custom exception classes
class UnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Underflow: No darts left to fire!";
    }
};

class OverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Overflow: Cannot exceed gun capacity!";
    }
};

// Define the nerfGun class
class nerfGun {
private:
    string model;
    int range;
    int capacity;
    int numDarts;

public:
    // Constructor
    nerfGun(const string& model, int range, int capacity)
        : model(model), range(range), capacity(capacity) {
        if (capacity > 144) {
            throw overflow_error("Capacity cannot exceed 144 darts");
        }
        numDarts = capacity; // Assume fully loaded when created
    }

    // Getter methods
    string getModel() const { return model; }
    int getCapacity() const { return capacity; }
    int getDartCount() const { return numDarts; }

    // Fire method
    void fire() {
        if (numDarts <= 0) {
            throw UnderflowException();
        }
        --numDarts;
    }

    // Reload method
    void reload(int quantity) {
        if (numDarts + quantity > capacity) {
            throw OverflowException();
        }
        numDarts += quantity;
    }

    // Overloaded operators
    bool operator==(const nerfGun& other) const {
        return (numDarts == other.numDarts);
    }

    bool operator<(const nerfGun& other) const {
        return (numDarts < other.numDarts);
    }

    nerfGun& operator--() {
        if (numDarts <= 0) {
            throw UnderflowException();
        }
        --numDarts;
        return *this;
    }

    nerfGun operator--(int) {
        nerfGun temp = *this;
        --(*this);
        return temp;
    }

    nerfGun& operator+=(int quantity) {
        if (numDarts + quantity > capacity) {
            throw OverflowException();
        }
        numDarts += quantity;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const nerfGun& gun) {
        os << "Model: " << gun.model << ", Range: " << gun.range << "ft, Capacity: "
           << gun.capacity << ", Darts: " << gun.numDarts;
        return os;
    }
};

int main() {
    vector<nerfGun> guns;

    // Creating different nerf guns
    nerfGun gun1("Alpha", 50, 50);
    nerfGun gun2("Delta", 40, 80);
    nerfGun gun3("Omega", 60, 100);
    nerfGun gun4("Beta", 30, 120);

    // Displaying each gun's information
    cout << gun1 << endl;
    cout << gun2 << endl;
    cout << gun3 << endl;
    cout << gun4 << endl;

    // Comparing guns based on ammunition
    if (gun1 == gun2) {
        cout << "Gun1 and Gun2 have the same amount of ammunition." << endl;
    } else {
        cout << "Gun1 and Gun2 have different amount of ammunition." << endl;
    }

    // Firing and reloading guns randomly
    try {
        --gun1;
        --gun2;
        --gun3; 
        --gun4; 
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    // Displaying updated gun information
    cout << gun1 << endl;
    cout << gun2 << endl;
    cout << gun3 << endl;
    cout << gun4 << endl;

    return 0;
}
