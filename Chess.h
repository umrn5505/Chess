// Chess.h
#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

#include "Board.h"
#include "Utility.h"
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

struct pos
{
    int x, y,xx,yy;
    Colour t;
};

class Chess {
private:

    vector <pos> moves_history;
    Board B;
    pos in{};
    Colour turn;
    int sx,sy,ex,ey;
    bool Hi[8][8]{};
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
    void startGame();
    void changeTurn();
    bool checkMove();
    void printMovesHistory();
    void showcheckMate();
public:
    Chess();
    void play();


};

#endif //CHESS_CHESS_H