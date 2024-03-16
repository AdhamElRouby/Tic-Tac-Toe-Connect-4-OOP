#include "../headers/player.h"
#include <ostream>

// constructors
Player::Player(string name, char symbol) {
    this->name = name;
    this->symbol = symbol;    
}

Player::Player(string name) {this->name = name;}

// getters
string Player::getName() const {return name;}
char Player::getSymbol() const {return symbol;}

// setters
void Player::setName(string name) {this->name = name;}
void Player::setSymbol(char symbol) {this->symbol = symbol;}

// overloading << operator
ostream& operator << (ostream& os, const Player& p) {
    os << "Player's name: " << p.name << '\n';
    os << "Player's symbol: " << p.symbol;
    return os;
}