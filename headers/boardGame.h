#ifndef BOARDGAME
#define BOARDGAME

#include "../sources/player.cpp"

class BoardGame {
    protected:
        int rows, columns;
        Player* curr_player;
        Player* p1;
        Player* p2;
        char** board;
        int countOfPlays; // used to check if there is a draw
        virtual void changePosToRowColumn(const int& pos, int& r, int& c) = 0;
        virtual void printBoardInstructions();
    public:
        BoardGame(int r, int c, Player* p1 = NULL, Player* p2 = NULL);
        virtual ~BoardGame();
        // getter
        Player* getCurrentPlayer();
        // setter
        void setPlayers(Player p1, Player p2);
        virtual void printInstructions() = 0; // although the instructions will be similar, but the rules of each game is different
        virtual void printBoard() = 0;
        void makeMove(const int& pos);
        bool isValidMove(const int& pos);
        BoardGame* operator +(const int& pos);
        virtual bool isGameOver() = 0;
        friend void runGame(BoardGame*board, Player& p1, Player&p2);
};

#endif