#ifndef CONNECTFOUR
#define CONNECTFOUR

#include "../sources/tictactoe.cpp"

class ConnectFour : public BoardGame {
    private:
        void changePosToRowColumn(const int& pos, int& r, int& c) override;
    public:
        ConnectFour();
        ConnectFour(Player p1, Player p2);
        void printInstructions() override;
        void printBoard() override;
        bool isGameOver() override;
};


#endif