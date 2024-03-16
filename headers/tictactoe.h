#ifndef TICTACTOE
#define TICTACTOE

#include "../sources/boardGame.cpp"


class TicTacToe : public BoardGame {
    private:
        void changePosToRowColumn(const int& pos, int& r, int& c) override;
        void printBoardInstructions() override;
    public:
        TicTacToe();
        TicTacToe(Player p1, Player p2);
        void printInstructions() override;
        void printBoard() override;
        bool isGameOver() override;
};


#endif