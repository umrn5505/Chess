//
// Created by umer on 4/19/24.
//

#include "Queen.h"
#include <iostream>
using namespace std;

Queen::Queen(int x, int y, Board *b, Colour col,char sym,int mv) : Piece(x, y, b, col,sym,mv) {}

void Queen::print() {
if(colour == White)
    cout << "\u265B";
else
    cout << "\u2655";
}

bool Queen::isLegal(int er, int ec) {
    return ((isDiagonalMove(_x,_y,er,ec)&& isDiagonalClear(_x,_y,er,ec,_b)) || (isHorizontalClear(_x,_y,er,ec,_b)&&
    isHorizontalMove(_x,_y,er,ec)) || (isVerticalMove(_x,_y,er,ec) && isVerticalClear(_x,_y,er,ec,_b)));
}

Colour Queen::getCol() {
    return colour;
}

char Queen::getChar() {
    return sym;
}

int Queen::getMoves() {
    return moveCounter;
}

void Queen::setMoves() {
    moveCounter++;
}

