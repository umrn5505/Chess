//
// Created by umer on 4/19/24.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include "Utility.h"

class Board;

class Piece{
protected:
    int _x,_y,er,ec;
    Board * _b;
    Colour colour;
    char sym;
    int moveCounter;

public:
    Piece(int x,int y,Board*b,Colour col,char sym,int mv);
    virtual void print() = 0;
    virtual bool isLegal(int er, int ec) = 0;
    void move(int nr,int nc);
    static bool isDiagonalClear(int _x,int _y,int er, int ec,Board* b);
    static bool isVerticalClear(int _x,int _y,int er, int ec,Board* b);
    static bool isHorizontalClear(int _x,int _y,int er, int ec,Board* b);
    static bool isHorizontalMove(int _x,int _y,int er, int ec);
    static bool isVerticalMove(int _x,int _y,int er, int ec);
    static bool isDiagonalMove(int _x,int _y,int er, int ec);
    virtual Colour getCol() = 0;
    virtual char getChar() = 0;
    virtual int getMoves() = 0;
    virtual void setMoves() = 0;


};


#endif //CHESS_PIECE_H
