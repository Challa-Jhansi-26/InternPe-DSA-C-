#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string getComputerChoice() {
    int choice = rand() % 3;
    switch (choice) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
    }
    return ""; // Default case (should not reach here)
}

string getPlayerChoice() {
    string choice;
    cout << "Enter Rock, Paper, or Scissors: ";
    cin >> choice;
    return choice;
}

string determineWinner(string playerChoice, string computerChoice) {
    if (playerChoice == computerChoice) {
        return "It's a tie!";
    } else if ((playerChoice == "Rock" && computerChoice == "Scissors") ||
               (playerChoice == "Paper" && computerChoice == "Rock") ||
               (playerChoice == "Scissors" && computerChoice == "Paper")) {
        return "You win!";
    } else {
        return "You lose!";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    char playAgain;
    do {
        string playerChoice = getPlayerChoice();
        string computerChoice = getComputerChoice();

        cout << "\nPlayer choice: " << playerChoice << endl;
        cout << "Computer choice: " << computerChoice << endl;
        cout << determineWinner(playerChoice, computerChoice) << endl;

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}
