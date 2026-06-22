#include <iostream>
#include <vector>

using namespace std;

struct Quiz {
    string question;
    vector<string> options;
    int correctOption;
};

int main() {
    vector<Quiz> quizzes = {
        {"What is the capital of France?", {"1. Berlin", "2. Madrid", "3. Paris", "4. Rome"}, 3},
        {"Which planet is known as the Red Planet?", {"1. Earth", "2. Mars", "3. Jupiter", "4. Venus"}, 2},
        {"What is the capital of India?", {"1. New Delhi", "2. Mumbai", "3. Kolkata", "4. Chennai"}, 1}
    };

    int score = 0;
    for (const auto& quiz : quizzes) {
        cout << quiz.question << endl;
        for (const auto& option : quiz.options) {
            cout << option << endl;
        }
        cout << "Enter your answer (1-4): ";
        int answer;
        cin >> answer;

        if (answer == quiz.correctOption) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! The correct answer is: " << quiz.options[quiz.correctOption - 1] << endl;
        }
        cout << endl;
    }

    cout << "Your final score is: " << score << "/" << quizzes.size() << endl;

    return 0;
}
