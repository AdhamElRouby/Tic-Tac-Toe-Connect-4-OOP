#include "../headers/boardGame.h"

BoardGame::BoardGame(int r, int c, Player* p1, Player* p2) {
    rows = r;
    columns = c;
    board = new char*[rows];
    for(int i = 0; i < rows; i++) {
        board[i] = new char[columns];
        // fill the array with empty spaces
        for(int j = 0; j < columns; j++) board[i][j] = ' ';
    }
    countOfPlays = 0;
    this->p1 = p1;
    this->p2 = p2;
    if(p1 && p2)
        curr_player = p1->getSymbol() == 'X' ? this->p1 : this->p2;
    else
        curr_player = NULL;
}

Player* BoardGame::getCurrentPlayer() {return curr_player;}

void BoardGame::setPlayers(Player p1, Player p2) {
    this->p1 = &p1;
    this->p2 = &p2;
    curr_player = p1.getSymbol() == 'X' ? this->p1 : this->p2;
}

BoardGame::~BoardGame() {
    for(int i = 0; i < rows; i++)
        delete [] board[i];

    delete [] board;
}

void BoardGame::printBoardInstructions() {
    printBoard();
}

bool BoardGame::isValidMove(const int& pos) {
    int r, c;
    changePosToRowColumn(pos, r, c);
    if(r >= rows || c >= columns) {
        cout << "Invalid Number! Number must be between 1 and 9!\n";
        return false;
    }
    if(!isblank(board[r][c])) {
        cout << "Invalid Number! The position you chose is already occupied!\n";
        return false;
    }
    return true;
}

void BoardGame::makeMove(const int& pos) {
    // this function is always called after isValidMove
    countOfPlays++;
    int r, c;
    changePosToRowColumn(pos, r, c);
    board[r][c] = curr_player->getSymbol();
    // swap player
    curr_player = curr_player == p1 ? p2 : p1;
}

BoardGame* BoardGame::operator+(const int& pos) {
    makeMove(pos);
    return this;
}

void runGame(BoardGame*board, Player& p1, Player&p2) {
    // printing the instructions
    board->printInstructions();
    // choosing symbols - just a way to direct the program
    char s1, s2;
    do {
        cout << p1.getName() << ", choose a symbol (X/O) & " << p2.getName() << " will get the other symbol: ";
        cin >> s1;
        s1 = toupper(s1);
    } while(s1 != 'X' && s1 != 'O');
    p1.setSymbol(s1);
    s2 = s1 == 'X' ? 'O' : 'X';
    p2.setSymbol(s2);
    // add the two players to the board
    board->setPlayers(p1, p2);
    // the actual run of the game
    while(!board->isGameOver()) {
        // note: printBoard() function is called inside isGameOver() function
        cout << board->getCurrentPlayer()->getName() << "'s Turn, ";
        int pos;
        do {
            cout << "Enter a position (1-9): ";
            cin >> pos;
        } while(!board->isValidMove(pos));
        // call makeMove() but with the '+' operator
        board = *board + pos;
    }
}