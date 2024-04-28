// Chess.h
#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

#include "Board.h"
#include "Utility.h"
#include "Piece.h"

class Chess {
private:
    Board B;
    Colour turn;
    int sx,sy,ex,ey;
    bool Hi[8][8]{};
public:
    Chess();
    void startGame();
    void changeTurn();
    bool checkMove();
    void play();
    bool isKill();
    void loadHighPath();
    void updateBoard();
    void findKing(int &, int &);
    bool isCheck();
    bool checkSrc();
    bool checkDest();
    bool selfCheck(int sr,int sc,int er,int ec);
    bool checkMate();
    bool findPawn(int &,int &);
    bool canCastle();
    void Castling();
    bool callUndo();
    bool isStalemate();
};

#endif //CHESS_CHESS_H