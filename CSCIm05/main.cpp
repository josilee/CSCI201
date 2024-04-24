#include <iostream>
#include <string>
using namespace std;

// Base class
class Beverage {
protected:
    string name;
    string description;
    int servingSize;
    int calories;
    double price;

public:
    Beverage(string name, string description, int servingSize, int calories, double price)
        : name(name), description(description), servingSize(servingSize), calories(calories), price(price) {}

    virtual ~Beverage() {}

    void setName(const string& newName) { name = newName; }
    void setDescription(const string& newDescription) { description = newDescription; }
    void setServingSize(int newServingSize) { servingSize = newServingSize; }
    void setCalories(int newCalories) { calories = newCalories; }
    void setPrice(double newPrice) { price = newPrice; }

    string getName() const { return name; }
    string getDescription() const { return description; }
    int getServingSize() const { return servingSize; }
    int getCalories() const { return calories; }
    double getPrice() const { return price; }

    virtual string toString() const {
        return "Name: " + name + "\nDescription: " + description + "\nServing Size: " 
               + to_string(servingSize) + " ml\nCalories: " + to_string(calories) 
               + " cal\nPrice: $" + to_string(price);
    }
};

// Derived class Coffee
class Coffee : public Beverage {
private:
    string temperature;  // Hot or Cold
    bool caffeinated;
    string roastType;
    string strength;
    bool creamer;
    bool sweetener;

public:
    Coffee(string name, string description, int servingSize, int calories, double price,
           string temperature, bool caffeinated, string roastType, string strength,
           bool creamer, bool sweetener)
        : Beverage(name, description, servingSize, calories, price), temperature(temperature),
          caffeinated(caffeinated), roastType(roastType), strength(strength), 
          creamer(creamer), sweetener(sweetener) {}

    virtual string toString() const override {
        return Beverage::toString() + "\nTemperature: " + temperature 
               + "\nCaffeinated: " + (caffeinated ? "Yes" : "No")
               + "\nRoast Type: " + roastType + "\nStrength: " + strength
               + "\nCreamer: " + (creamer ? "Yes" : "No") + "\nSweetener: " + (sweetener ? "Yes" : "No");
    }
};

// Derived class Tea
class Tea : public Beverage {
private:
    string type;
    string temperature;
    bool creamer;
    bool sweetener;
    bool lemon;

public:
    Tea(string name, string description, int servingSize, int calories, double price,
        string type, string temperature, bool creamer, bool sweetener, bool lemon)
        : Beverage(name, description, servingSize, calories, price), type(type),
          temperature(temperature), creamer(creamer), sweetener(sweetener), lemon(lemon) {}

    virtual string toString() const override {
        return Beverage::toString() + "\nType: " + type + "\nTemperature: " + temperature
               + "\nCreamer: " + (creamer ? "Yes" : "No") + "\nSweetener: " + (sweetener ? "Yes" : "No")
               + "\nLemon: " + (lemon ? "Yes" : "No");
    }
};

// Derived class Soda
class Soda : public Beverage {
private:
    string brand;
    string type;
    bool diet;

public:
    Soda(string name, string description, int servingSize, int calories, double price,
         string brand, string type, bool diet)
        : Beverage(name, description, servingSize, calories, price), brand(brand), type(type), diet(diet) {}

    virtual string toString() const override {
        return Beverage::toString() + "\nBrand: " + brand + "\nType: " + type + "\nDiet: " + (diet ? "Yes" : "No");
    }
};

// Derived class EnergyDrink
class EnergyDrink : public Beverage {
private:
    string brand;
    string stimulant;
    bool sweetener;

public:
    EnergyDrink(string name, string description, int servingSize, int calories, double price,
                string brand, string stimulant, bool sweetener)
        : Beverage(name, description, servingSize, calories, price), brand(brand), stimulant(stimulant), sweetener(sweetener) {}

    virtual string toString() const override {
        return Beverage::toString() + "\nBrand: " + brand + "\nStimulant: " + stimulant
               + "\nSweetener: " + (sweetener ? "Yes" : "No");
    }
};

int main() {
    // Creating instances of each beverage type
    Coffee coffee("Coffee", "Rich and full-bodied", 250, 10, 2.5, "Hot", true, "Espresso", "Strong", true, true);
    Tea tea("Green Tea", "Smooth and refreshing", 200, 0, 1.5, "Green", "Hot", false, false, true);
    Soda soda("Coke", "Classic flavor", 330, 140, 1.0, "Coca-Cola", "Cola", false);
    EnergyDrink energyDrink("Monster", "High energy boost", 500, 200, 3.0, "Monster", "Caffeine", true);

    // Displaying each beverage
    cout << coffee.toString() << endl << endl;
    cout << tea.toString() << endl << endl;
    cout << soda.toString() << endl << endl;
    cout << energyDrink.toString() << endl;

    return 0;
}
