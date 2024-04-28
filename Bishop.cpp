//
// Created by umer on 4/19/24.
//

#include "Bishop.h"
#include <iostream>
using namespace std;

Bishop::Bishop(int x, int y, Board *b, Colour col,char sym,int mv) : Piece(x, y, b, col,sym,mv) {}

void Bishop::print() {
if(colour == White)
    cout << "\u265D";
else
    cout << "\u2657";
}

bool Bishop::isLegal(int er, int ec) {
    return (isDiagonalMove(_x,_y,er,ec) && isDiagonalClear(_x,_y,er,ec,_b));
}

Colour Bishop::getCol() {
    return colour;
}

char Bishop::getChar() {
    return sym;
}

int Bishop::getMoves() {
    return moveCounter;
}

void Bishop::setMoves() {
moveCounter++;
}

