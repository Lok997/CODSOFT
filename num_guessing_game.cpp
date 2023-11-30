#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    // Initialize the user's guess
    int guess;

    // Start the guessing game
    do
    {
        // Prompt the user to enter their guess
        cout << "Enter your guess: ";
        cin >> guess;

        // Provide feedback based on the user's guess
        if (guess > randomNumber)
        {
            cout << "Your guess is too high." << endl;
        }
        else if (guess < randomNumber)
        {
            cout << "Your guess is too low." << endl;
        }
    } while (guess != randomNumber);

    // Congratulate the user on guessing correctly
    cout << "Congratulations! You guessed the correct number!" << endl;

    return 0;
}