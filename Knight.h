//
// Created by umer on 4/19/24.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "Piece.h"

class Knight:public Piece{
public:
    Knight(int x, int y, Board* b, Colour col,char sym,int mv);
    void print();
    bool isLegal(int er, int ec);
    Colour getCol();
    char getChar();
    int getMoves();
    void setMoves();
};


#endif //CHESS_KNIGHT_H
