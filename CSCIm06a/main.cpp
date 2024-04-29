#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class
class Player {
protected:
    string name;
    int playerID;
public:
    Player(const string& name, int playerID) : name(name), playerID(playerID) {}
    virtual ~Player() {} // Virtual destructor
    virtual string getPlayerPosition() const = 0;
    virtual void play() const = 0;
    virtual string toString() const = 0;
};

// Offense class and its subclasses
class QuarterBack : public Player {
public:
    QuarterBack(const string& name, int playerID) : Player(name, playerID) {}

    string getPlayerPosition() const override {
        return "Quarterback";
    }

    void play() const override {
        cout << "Passing or handing off the ball\n";
    }

    string toString() const override {
        return "Name: " + name + ", Number: " + to_string(playerID) + ", Position: Quarterback";
    }
};

// Defense class and its subclasses
class DefensiveLineman : public Player {
public:
    DefensiveLineman(const string& name, int playerID) : Player(name, playerID) {}

    string getPlayerPosition() const override {
        return "Defensive Lineman";
    }

    void play() const override {
        cout << "Tackling, rushing the passer\n";
    }

    string toString() const override {
        return "Name: " + name + ", Number: " + to_string(playerID) + ", Position: Defensive Lineman";
    }
};

// Special Teams class and its subclasses
class Kicker : public Player {
public:
    Kicker(const string& name, int playerID) : Player(name, playerID) {}

    string getPlayerPosition() const override {
        return "Kicker";
    }

    void play() const override {
        cout << "Kicking field goals or extra points\n";
    }

    string toString() const override {
        return "Name: " + name + ", Number: " + to_string(playerID) + ", Position: Kicker";
    }
};

int main() {
    vector<Player*> team; // Vector to hold players

    // Adding players to the team
    team.push_back(new QuarterBack("Tom Brady", 12));
    team.push_back(new DefensiveLineman("Aaron Donald", 99));
    team.push_back(new Kicker("Justin Tucker", 9));

    // Printing out the list of players on the team
    cout << "Players on the team:\n";
    for (const auto& player : team) {
        cout << player->toString() << endl;
        player->play(); // Indicate how the player participates in the game
    }

    // Displaying the number of players on the team
    cout << "\nNumber of players on the team: " << team.size() << endl;

    // Freeing memory
    for (auto player : team) {
        delete player;
    }

    return 0;
}
