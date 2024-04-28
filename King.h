//
// Created by umer on 4/19/24.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "Piece.h"

class King: public Piece{
public:
    King(int x, int y, Board* b,Colour col,char sym,int mv);
    void print();
    bool isLegal(int er, int ec);
    Colour getCol();
    char getChar();
    int getMoves();
    void setMoves();
};


#endif //CHESS_KING_H
