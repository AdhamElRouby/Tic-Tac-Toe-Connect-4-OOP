#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class Player {
    private:
        // private attributes
        string name;
        char symbol;
    public:
        // parameterized constructor
        Player() {}
        Player(string name);
        Player(string name, char symbol);
        // getters
        string getName() const;
        char getSymbol() const;
        // setters
        void setName(string name);
        void setSymbol(char symbol);
        // friend function to overlaod << operator
        friend ostream& operator << (ostream& os, const Player& p);
};


#endif