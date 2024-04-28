//
// Created by umer on 4/19/24.
//

#include "Knight.h"
#include <iostream>
using namespace std;

Knight::Knight(int x, int y, Board *b, Colour col,char sym,int mv) : Piece(x, y, b, col,sym,mv) {}

void Knight::print() {
if(colour == White)
    cout << "\u265E";
else
    cout << "\u2658";
}

bool Knight::isLegal(int er, int ec) {
    int dx = abs(_x - er);
    int dy = abs(_y - ec);
    return ((dx == 1 && dy == 2) || (dx == 2 && dy == 1));
}

Colour Knight::getCol() {
    return colour;
}

char Knight::getChar() {
    return sym;
}

int Knight::getMoves() {
    return moveCounter;
}

void Knight::setMoves() {
    moveCounter++;
}

