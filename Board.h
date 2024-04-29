//
// Created by umer on 4/19/24.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Utility.h"

class Chess;

class Board {
private:
    Piece* Bs[8][8];
public:

    void InitializeBoard();
    void printBoard();
    Piece* pieceAt(int x, int y);
    void move(int r, int c,int er, int ec);
    bool isPawnKill(int er,int ec,Colour col);
    void setPiece(int x,int,Piece* A);
    void pawnPromotion(int x,int y,Colour col);
    void writeToFile();
    void loadFromFile();
    void writeToFile2(Colour turn);
    void loadFromFile2(char &);

};


#endif //CHESS_BOARD_H
