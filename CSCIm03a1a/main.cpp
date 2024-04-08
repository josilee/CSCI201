#include <iostream>
#include <array>

using namespace std;

// Function prototypes
void getData(array<int, 16>& scores);
int highScore(const array<int, 16>& scores);
int lowScore(const array<int, 16>& scores);
double calculateAverage(const array<int, 16>& scores);

int main() {
    array<int, 16> quizScores;
    int highModule, lowModule;
    double averageScore;

    // Get quiz scores from the user
    getData(quizScores);

    // Calculate high and low module numbers (not scores)
    highModule = highScore(quizScores);
    lowModule = lowScore(quizScores);

    // Calculate the average score
    averageScore = calculateAverage(quizScores);

    // Print the report
    cout << "Fall 2019 Quiz Grades:\n\n";
    for (int i = 0; i < 16; ++i) {
        cout << "            Module " << (i + 1) << ":  " << quizScores[i] << "\n";
    }
    cout << "\nAverage Grade: " << averageScore << "\n";
    cout << "Your lowest score was in Module " << lowModule + 1 << " with " << quizScores[lowModule] << ".\n";
    cout << "Your highest score was in Module " << highModule + 1 << " with " << quizScores[highModule] << ".\n";

    return 0;
}

// Function definitions

void getData(array<int, 16>& scores) {
    for (int i = 0; i < 16; ++i) {
        do {
            cout << "Enter score for Module " << (i + 1) << " (0-15): ";
            cin >> scores[i];
            if (scores[i] < 0 || scores[i] > 15) {
                cout << "Invalid score. Please enter a value between 0 and 15.\n";
            }
        } while (scores[i] < 0 || scores[i] > 15);
    }
}

int highScore(const array<int, 16>& scores) {
    int indexHigh = 0;
    for (int i = 1; i < 16; ++i) {
        if (scores[i] > scores[indexHigh]) {
            indexHigh = i;
        }
    }
    return indexHigh;
}

int lowScore(const array<int, 16>& scores) {
    int indexLow = 0;
    for (int i = 1; i < 16; ++i) {
        if (scores[i] < scores[indexLow]) {
            indexLow = i;
        }
    }
    return indexLow;
}

double calculateAverage(const array<int, 16>& scores) {
    double sum = 0;
    for (int score : scores) {
        sum += score;
    }
    return sum / scores.size();
}
