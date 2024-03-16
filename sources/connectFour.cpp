#include "../headers/connectFour.h"

// constructors
ConnectFour::ConnectFour() : BoardGame(6, 7) {}
ConnectFour::ConnectFour(Player p1, Player p2) : BoardGame(6, 7, &p1, &p2) {}

// class's methods
void ConnectFour::printInstructions() {
    cout << "\nThis is a connect four game. From the following board, you will be asked to enter the number of column to play with symbols X or O:\n";
    printBoardInstructions();
    cout << "Please, press Enter to start the game...";
    cin.sync();
    while(cin.get() != '\n') {}
    cout << '\n';
}

void ConnectFour::printBoard() {
    cout << '\n';
    for(int i = 1; i <= 7; i++)
        cout << "--" << i << "--";
    
    cout << '\n';

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++)
            cout << "| " << board[i][j] << " |";
        cout << '\n';
    }
    cout << '\n';
}

void ConnectFour::changePosToRowColumn(const int& pos, int& r, int& c) {
    int ri = 5;
    while(!isblank(board[ri][pos - 1])) {
        ri--;
        if(ri == 0) break;
    }
    r = ri;
    c = pos - 1;
}

bool ConnectFour::isGameOver() {
    printBoard();

    Player* winP = curr_player == p1 ? p2 : p1;

    // Horizontal Check
    for(int j = 0; j < columns - 3; j++) {
        for(int i = rows - 1; i >= 0; i--) // check the rows from the bottom
            if(!isblank(board[i][j]) && board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3]) {
                cout << "Game Over! " << winP->getName() << " has won!\n";
                return true; 
            }
    }
    // Vertical Check
    for(int i = 0; i < rows - 3; i++) {
        for(int j = 0; j < columns; j++)
            if(!isblank(board[i][j]) && board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j]) {
                cout << "Game Over! " << winP->getName() << " has won!\n";
                return true; 
            }
    }

    // check for ascending diagonals
    for(int i = 3; i < rows; i++) { // from 3 to 6
        for(int j = 0; j < columns - 3; j++) // from 0 to 3
            if(!isblank(board[i][j]) && board[i][j] == board[i-1][j+1] && board[i][j] == board[i-2][j-2] && board[i][j] == board[i-3][j-3]) {
                cout << "Game Over! " << winP->getName() << " has won!\n";
                return true;   
            }
    }

    // check for descending diagonals
    for(int i = 0; i < rows - 3; i++) { // from 0 to 2
        for(int j = 0; j < columns - 3; j++) // from 0 to 3
            if(!isblank(board[i][j]) && board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3]) {
                cout << "Game Over! " << winP->getName() << " has won!\n";
                return true;   
            }
    }    

    // check for draw
    if(countOfPlays == rows * columns) {
        cout << "GAME OVER! IT'S A TIE!\n";
        return true;
    }

    return false;
}