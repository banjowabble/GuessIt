#include <bits/stdc++.h>
using namespace std;

int generateRandomNumber ();
int getPlayerGuess ();
void printAnswer (int guess, int secretNumber);
void playGuessIt();

int main (int argc, char* argv[])
{
    srand(time(NULL));
    string answer;
    do
    {
        playGuessIt();
        cout << "\nDo you want to keep playing (yes or no)?";
        cin >> answer;
    }while (answer == "yes");
    cout << "Game over";
    return 0;
}

int generateRandomNumber ()
{
    return rand() % 100 + 1;
}

int getPlayerGuess ()
{
    int guess;
    cout << "Enter your guess (1 -100): ";
    cin >> guess;
    return guess;
}

void printAnswer (int guess, int secretNumber, int guessTimes)
{
    if (guess < secretNumber) cout << "Try a bigger number\n";
    else if (guess > secretNumber) cout << "Try a smaller number\n";
    else cout << "Congrats! You won the game wiht a score of: " << 100 - guessTimes;
}

void playGuessIt()
{
    int secretNumber = generateRandomNumber ();
    int guess;
    int guessTimes = 0;

    do
    {
        guess = getPlayerGuess ();
        printAnswer (guess, secretNumber, guessTimes);
        guessTimes++;
    } while (guess != secretNumber);
}
