#include <iostream>

using namespace std;

// Function to display the current game board
void displayBoard(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(char board[][3], char player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

// Function to get the next player's turn
char getNextPlayer(char currentPlayer)
{
    if (currentPlayer == 'X')
    {
        return 'O';
    }
    else
    {
        return 'X';
    }
}

int main()
{
    char board[3][3] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    char currentPlayer = 'X';

    while (true)
    {
        // Display the current board
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row, col): ";
        cin >> row >> col;

        // Validate the user's input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-')
        {
            cout << "Invalid move. Please try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            cout << "Player " << currentPlayer << " has won!" << endl;
            break;
        }

        // Check if the game is a draw
        if (checkDraw(board))
        {
            displayBoard(board);
            cout << "The game is a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = getNextPlayer(currentPlayer);
    }

    // Ask if the players want to play another game
    cout << "Do you want to play again? (Y/N): ";
    char choice;
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        main();
    }
    else
    {
        cout << "Thank you for playing!" << endl;
    }

    return 0;
}