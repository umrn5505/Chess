//
// Created by umer on 4/19/24.
//

#include "King.h"
#include <iostream>
using namespace std;

King::King(int x, int y, Board *b, Colour col,char sym,int mv) : Piece(x, y, b, col,sym,mv) {}

void King::print() {
if(colour == White)
    cout << "\u265A";
else
    cout << "\u2654";
}

bool King::isLegal(int er, int ec) {
    int dr = abs(_x - er);
    int dc = abs(_y - ec);
    if ((dr <= 1) && (dc <= 1)) {
        if ((isDiagonalMove(_x, _y, er, ec) && isDiagonalClear(_x, _y, er, ec, _b)) ||
            (isHorizontalClear(_x, _y, er, ec, _b) && isHorizontalMove(_x, _y, er, ec)) ||
            (isVerticalMove(_x, _y, er, ec) && isVerticalClear(_x, _y, er, ec, _b))) {
            return true;
        }
    }
    return false;
}

Colour King::getCol() {
    return colour;
}

char King::getChar() {
    return sym;
}


int King::getMoves() {
    return moveCounter;
}

void King::setMoves() {
    moveCounter++;
}

