#include "../headers/tictactoe.h"

// constructors
TicTacToe::TicTacToe() : BoardGame(3, 3) {}
TicTacToe::TicTacToe(Player p1, Player p2) : BoardGame(3, 3, &p1, &p2) {}

// class's methods
void TicTacToe::printInstructions() {
    cout << "\nThis is a tic tac toe game. From the following board, you will be asked to enter the number of block to play X or O:\n";
    printBoardInstructions();
    cout << "Please, press Enter to start the game...";
    cin.sync();
    while(cin.get() != '\n') {}
    cout << '\n';
}

void TicTacToe::printBoardInstructions() {
    cout << '\n';
    cout << "     |     |     \n";
    cout << "  1  |  2  |  3  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  4  |  5  |  6  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  7  |  8  |  9  \n";
    cout << "     |     |     \n";
    cout << '\n';
}

void TicTacToe::printBoard() {
    cout << "\n";
    for(int i = 0; i < rows; i++) {
        cout << "     |     |     \n";
        cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] <<  " \n";
        if(i != rows - 1)
            cout << "_____|_____|_____\n";
        else
            cout << "     |     |     \n";
    }
    cout << "\n";
}

void TicTacToe::changePosToRowColumn(const int& pos, int& r, int& c) {
    r = (pos - 1)/rows;
    c = (pos - 1) % columns;
}

bool TicTacToe::isGameOver() {
    printBoard();

    Player* winP = curr_player == p1 ? p2 : p1;
    // first check for rows
    for(int i = 0; i < 3; i++) {
        if(!isblank(board[i][1]) && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            cout << "Game Over! " << winP->getName() << " has won!\n";
            return true; 
        } 
    }

    // now, check for colummns
    for(int i = 0; i < 3; i++) {
        if(!isblank(board[1][i]) && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            cout << "Game Over! " << winP->getName() << " has won!\n";
            return true; 
        } 
    }

    // if not, now check for diagonals
        // first diagonal
    if(!isblank(board[1][1]) && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        cout << "Game Over! " << winP->getName() << " has won!\n";
        return true; 
    } 
        // second diagonal
    else if(!isblank(board[1][1]) && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        cout << "Game Over! " << winP->getName() << " has won!\n";
        return true; 
    }

    // check for draw
    if(countOfPlays == rows * columns) {
        cout << "GAME OVER! IT'S A TIE!\n";
        return true;
    }

    return false;
}