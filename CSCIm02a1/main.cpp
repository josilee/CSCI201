#include <iostream>
#include <stdexcept>
#include <string>
#include <array>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
    static const array<string, 12> monthNames;

    // Helper function to check if day is valid for month
    bool isValidDay(int d, int m) const {
        static const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return d >= 1 && d <= daysPerMonth[m - 1];
    }

public:
    Date(int m, int d, int y) {
        if (m < 1 || m > 12) throw invalid_argument("Invalid month - there are only 12 months in the year.");
        if (y < 1900 || y > 2020) throw invalid_argument("Invalid year, must be between 1900 and 2020.");
        if (!isValidDay(d, m)) throw invalid_argument("Invalid day for this month.");

        month = m;
        day = d;
        year = y;
    }

    void setMonth(int m) {
        if (m < 1 || m > 12) throw invalid_argument("Invalid month, only 12 months in the year.");
        if (!isValidDay(day, m)) throw invalid_argument("Invalid day for the newly month.");
        month = m;
    }

    void setDay(int d) {
        if (!isValidDay(d, month)) throw invalid_argument("Invalid day for the month.");
        day = d;
    }

    void setYear(int y) {
        if (y < 1900 || y > 2020) throw invalid_argument("Invalid year, must be between 1900 and 2020.");
        year = y;
    }

    string toString() const {
        return monthNames[month - 1] + " " + to_string(day) + ", " + to_string(year);
    }
};

const array<string, 12> Date::monthNames = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main() {
    int month, day, year;

    // User input for initial date
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter year (1900-2020): ";
    cin >> year;

    try {
        Date date(month, day, year);
        cout << "Initial Date: " << date.toString() << endl;

        // Change month
        cout << "Enter new month (1-12): ";
        cin >> month;
        date.setMonth(month);
        cout << "New Date: " << date.toString() << endl;

        // Change day
        cout << "Enter new day: ";
        cin >> day;
        date.setDay(day);
        cout << "New Date: " << date.toString() << endl;

        // Change year
        cout << "Enter new year (1900-2020): ";
        cin >> year;
        date.setYear(year);
        cout << "New Date: " << date.toString() << endl;

    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
