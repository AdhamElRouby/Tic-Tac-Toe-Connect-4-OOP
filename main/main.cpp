#include <iostream>
#include "../sources/connectFour.cpp"
// connectFour.cpp connects to tictactoe.cpp & boardGame.cpp
using namespace std;

int main() {

    BoardGame* board;
    Player p1("Abdelrahman"), p2("Adham");
    int option;

    // choose type of the game:
    cout << "************** Welcome to GameBoardGo! **************\n";
    cout << "From the following games: \n";
    cout << "(1) TicTacToe (X/O) \t\t (2) Connect Four\n";
    
    // choose the type of the game
    do {
        cout << "Choose the game you want to play (Enter 1 or 2 ONLY): ";
        cin >> option;
    } while(option != 1 && option != 2);
    
    // connect the board to the game wanted to play
    if(option == 1)
        board = new TicTacToe();
    else // option == 2
        board = new ConnectFour();

    // run the game
    runGame(board, p1,  p2); // a friend function in boardGame class

    // release the memory
    delete board;

    return 0;
}