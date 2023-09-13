#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}

// Function to check if the current player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // If any empty space is found, the game is not a draw
            }
        }
    }
    return true; // All spaces are filled, and no player has won, so it's a draw
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameover = false;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (!gameover) {
        displayBoard(board);
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        int row, col;
        std::cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
            gameover = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            std::cout << "It's a draw!" << std::endl;
            gameover = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
        }
    }

    std::cout << "Do you want to play again? (yes/no): ";
    std::string playAgain;
    std::cin >> playAgain;

    if (playAgain == "yes" || playAgain == "Yes") {
        // Reset the board and start a new game
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
        gameover = false;
    } else {
        std::cout << "Thank you for playing Tic-Tac-Toe!" << std::endl;
    }

    return 0;
}



