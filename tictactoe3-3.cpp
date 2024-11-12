#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

char board[3][3] = {          // A 3x3 board is initialized to represent the Tic Tac Toe grid.
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

char ai = 'X';                // The AI will use the character 'X'
char human = 'O';             // The human player will use the character 'O'
char currentPlayer = human;   // Set the human as the starting player

// Function to print the Tic Tac Toe board
void printBoard() {
    for (int i = 0; i < 3; i++) {                     // Loop over rows
        for (int j = 0; j < 3; j++) {                 // Loop over columns
            cout << board[i][j];                      // Print each cell
            if (j < 2) cout << " | ";                 // Print vertical dividers
        }
        cout << endl;
        if (i < 2) cout << "--|---|--" << endl;       // Print horizontal dividers between rows
    }
    cout << endl;
}

// Function to check if any moves are left
bool isMovesLeft() {
    for (int i = 0; i < 3; i++)                       // Loop through rows
        for (int j = 0; j < 3; j++)                   // Loop through columns
            if (board[i][j] == ' ')                   // If there's an empty cell
                return true;                          // Moves are available
    return false;                                     // No moves left
}

// Function to check for a winner or tie
char checkWinner() {
    for (int i = 0; i < 3; i++) {                     // Check rows and columns for a winner
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];                       // Winner in row
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];                       // Winner in column
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];                           // Winner on diagonal from top left to bottom right
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];                           // Winner on diagonal from top right to bottom left

    if (!isMovesLeft())
        return 'T';                                   // Tie if no moves left and no winner

    return ' ';                                       // Game is ongoing
}

// Minimax algorithm for AI move calculation
int minimax(bool isMaximizing) {
    char result = checkWinner();                      // Check if there's a winner or tie
    if (result == ai) return 10;                      // AI win returns 10
    if (result == human) return -10;                  // Human win returns -10
    if (result == 'T') return 0;                      // Tie returns 0

    if (isMaximizing) {                               // Maximizing for AI's turn
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {             // Check available cells
                    board[i][j] = ai;                 // Try AI's move
                    int score = minimax(false);       // Recursively minimize opponent's score
                    board[i][j] = ' ';                // Undo move
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {                                          // Minimizing for human's turn
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {             // Check available cells
                    board[i][j] = human;              // Try human's move
                    int score = minimax(true);        // Recursively maximize AI's score
                    board[i][j] = ' ';                // Undo move
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

// Find the best move for the AI
void bestMove() {
    int bestScore = -1000;
    int moveRow = -1, moveCol = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {                 // Check available cells
                board[i][j] = ai;                     // AI's hypothetical move
                int score = minimax(false);           // Evaluate move with minimax
                board[i][j] = ' ';                    // Undo move
                if (score > bestScore) {              // Update best move if score is higher
                    bestScore = score;
                    moveRow = i;
                    moveCol = j;
                }
            }
        }
    }

    if (moveRow != -1 && moveCol != -1) {             // Execute the best move
        board[moveRow][moveCol] = ai;
        currentPlayer = human;                        // Switch turn to human
    }
}

// Function to handle human player's move
void humanMove() {
    int row, col;
    do {
        cout << "Enter your move (row and column): ";
        cin >> row >> col;
        row--; col--;                                 // Adjust for zero-based indexing
    } while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ');  // Validate move

    board[row][col] = human;                          // Execute human move
    currentPlayer = ai;                               // Switch turn to AI
}

// Main function for the game loop
int main() {
    cout << "Tic Tac Toe - Human (O) vs AI (X)" << endl;
    printBoard();                                     // Print the initial empty board

    while (checkWinner() == ' ' && isMovesLeft()) {   // Loop until there's a winner or no moves left
        if (currentPlayer == human) {
            humanMove();                              // Human's turn
        } else {
            bestMove();                               // AI's turn
        }
        printBoard();                                 // Print board after each move
    }

    char result = checkWinner();                      // Check game result
    if (result == ai) {
        cout << "AI wins!" << endl;
    } else if (result == human) {
        cout << "You win!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;                                         // End of program
}