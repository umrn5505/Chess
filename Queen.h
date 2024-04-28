//
// Created by umer on 4/19/24.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Piece.h"

class Queen: public Piece{
public:
    Queen(int x, int y, Board* b,Colour col,char sym,int mv);
    void print();
    bool isLegal(int er, int ec);
    Colour getCol();
    char getChar();
    int getMoves();
    void setMoves();
};


#endif //CHESS_QUEEN_H
