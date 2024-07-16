#include <iostream>
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time()
using namespace std;

void printWelcomeMessage() {
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Guess the number between 1 and 100." << endl;
}

void printTryAgainMessage() {
    cout << "\nTry again!" << endl;
}

void printGameOverMessage(int secretNumber) {
    cout << "Thanks for playing!" << endl;
    
}

void printCongratulationsMessage() {
    cout << "\nCongratulations! You guessed the number!" << endl;
    
}

void playGame() {
    int secretNumber = rand() % 100 + 1;  // Random number between 1 and 100
    int guess;

    cout << "\nEnter your guess (1-100): ";
    while (true) {
        cin >> guess;

        if (guess < 1 || guess > 100) {
            cout << "Please enter a number between 1 and 100." << endl;
            continue;
        }

        if (guess == secretNumber) {
            printCongratulationsMessage();
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! Try a higher number." << endl;
        } else {
            cout << "Too high! Try a lower number." << endl;
        }

        printTryAgainMessage();
        cout << "Enter your guess (1-100): ";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation
    char playAgain;

    printWelcomeMessage();

    do {
        playGame();
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    printGameOverMessage(0);  // No secret number to reveal at the end
    return 0;
}
