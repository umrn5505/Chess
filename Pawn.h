//
// Created by umer on 4/19/24.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "Piece.h"
#include "Utility.h"

class Pawn: public Piece{

public:
    Pawn(int x, int y, Board* b, Colour col,char sym,int mv);
    void print();
    bool isLegal(int er, int ec);
    Colour getCol();
    char getChar();
    int getMoves();
    void setMoves();

};


#endif //CHESS_PAWN_H
