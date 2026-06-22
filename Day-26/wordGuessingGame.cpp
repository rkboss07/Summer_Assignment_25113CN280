#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string getRandomWord();
void replaceDashWithCorrectLetter(string& s1, char character, string& s2);
bool isLetterInWord(const string& word, char letter);


int main() {
    string wordToGuess = getRandomWord();
    int lives = 3;
    string guessedWord(wordToGuess.size(), '_');
    cout << "Welcome to the Word Guessing Game!" << endl;
    cout << "You have " << lives << " lives to guess the word." << endl
            << "The word has " << wordToGuess.size() << " letters." << endl;
    
    while (lives > 0 && guessedWord != wordToGuess) {
        cout << "Current word: " << guessedWord << endl;
        cout << "Enter a letter: ";
        char guess;
        cin >> guess;
        if (isLetterInWord(wordToGuess, guess)) {
            replaceDashWithCorrectLetter(wordToGuess, guess, guessedWord);
            cout << "Correct! The letter '" << guess << "' is in the word." << endl;
        } else {
            lives--;
            cout << "Wrong! The letter '" << guess << "' is not in the word." << endl;
            cout << "You have " << lives << " lives left." << endl;
        }
    
    
    }
    if (guessedWord == wordToGuess) {
        cout << "Congratulations! You've guessed the word: " << wordToGuess << endl;
    } else {
        cout << "Game Over! The correct word was: " << wordToGuess << endl;
    }
    return 0;
}

string getRandomWord() {
    vector<string> words = {"programming", "hangman", "challenge", "cplusplus", "developer"};
    srand(time(0));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

void replaceDashWithCorrectLetter(string& s1, char character, string& s2 ) {
    for (int i = 0; i < s1.size(); i++){
        if(tolower(s1[i]) == tolower(character)){
            s2[i] = s1[i];
        }
    }
}

bool isLetterInWord(const string& word, char letter) {
    for (char c : word) {
        if (tolower(c) == tolower(letter)) {
            return true;
        }
    }
    return false;
}