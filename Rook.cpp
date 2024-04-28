//
// Created by umer on 4/19/24.
//

#include "Rook.h"
#include <iostream>
using namespace std;

Rook::Rook(int x, int y, Board *b, Colour col,char sym,int mv) : Piece(x, y, b, col,sym,mv) {}

void Rook::print() {
if(colour == White)
    cout << "\u265C";
else
    cout << "\u2656";
}

bool Rook::isLegal(int er, int ec) {
    return ((isHorizontalMove(_x,_y,er,ec) && (isHorizontalClear(_x,_y,er,ec,_b))) || (isVerticalMove(_x,_y,er,ec) && isVerticalClear(_x,_y,er,ec,_b)));
}

Colour Rook::getCol() {
    return colour;
}

char Rook::getChar() {
    return sym;
}
int Rook::getMoves() {
    return moveCounter;
}

void Rook::setMoves() {
    moveCounter++;
}

