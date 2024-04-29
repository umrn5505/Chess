//
// Created by umer on 4/19/24.
//

#include "Pawn.h"
#include "Board.h"
#include<iostream>
using namespace std;


Pawn::Pawn(int x, int y, Board *b, Colour col, char sym,int mv) : Piece(x, y, b, col,sym,mv) {}

void Pawn::print()
{
if(colour == White)
    cout << "\u265F";
else
    cout << "\u2659";
}

bool Pawn::isLegal(int er, int ec) {
    int dr = _x - er;
    int dc = _y - ec;
    if ((_x == 1 && colour == Black) && (dr == -1 || dr == -2) && dc == 0 && (isVerticalMove(_x, _y, er, ec) && isVerticalClear(_x, _y, er, ec, _b)) && !_b->isPawnKill(er,ec,colour))
        return true;
    else if ((_x == 6 && colour == White) && (dr == 1 || dr == 2) && (isVerticalMove(_x, _y, er, ec) && isVerticalClear(_x, _y, er, ec, _b)) && !_b->isPawnKill(er,ec,colour))
        return true;
    else if ((colour == Black) && (dr == -1) && (isVerticalMove(_x, _y, er, ec) && isVerticalClear(_x, _y, er, ec, _b)) && !_b->isPawnKill(er,ec,colour))
        return true;
    else if ((colour == White) && (dr == 1) && (isVerticalMove(_x, _y, er, ec) && isVerticalClear(_x, _y, er, ec, _b)) && !_b->isPawnKill(er,ec,colour))
        return true;
    else if((colour == Black) && (dr == -1 )&& (dc == -1 || dc == 1) && isDiagonalClear(_x,_y,er,ec,_b) && isDiagonalMove(_x,_y,er,ec) && _b->isPawnKill(er,ec,colour))
        return true;
    else if((colour == White) && (dr == 1 ) && (dc == 1 || dc == -1) && isDiagonalClear(_x,_y,er,ec,_b) && isDiagonalMove(_x,_y,er,ec) && _b->isPawnKill(er,ec,colour))
        return true;
    else
        return false;
}


Colour Pawn::getCol() {
    return colour;
}

char Pawn::getChar() {
    return sym;
}

int Pawn::getMoves() {
    return moveCounter;
}

void Pawn::setMoves() {
    moveCounter++;
}


