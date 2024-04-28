//
// Created by umer on 4/19/24.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "Piece.h"

class Rook: public Piece{
public:
    Rook(int x, int y, Board* b,Colour col,char sym,int mv);
    void print();
    bool isLegal(int er, int ec);
    Colour getCol();
    char getChar();
    int getMoves();
    void setMoves();
};


#endif //CHESS_ROOK_H
