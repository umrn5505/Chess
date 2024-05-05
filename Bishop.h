//
// Created by umer on 4/19/24.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(int x, int y, Board *b, Colour col, char sym, int mv);

    void print();

    bool isLegal(int er, int ec);

    Colour getCol();

    char getChar();

    int getMoves();

    void setMoves();
};


#endif //CHESS_BISHOP_H
