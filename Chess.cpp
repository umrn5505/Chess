#include "Chess.h"
#include<iostream>
#include <thread>
#include <chrono>

using namespace std;
#include <SFML/Graphics.hpp>
void Chess::startGame() {
    B.InitializeBoard();
}

bool Chess::checkMove() {
    return (B.pieceAt(sx,sy)->isLegal(ex,ey));
}

Chess::Chess() {
    turn = Black;
    cout << "If you want to start a new game enter 1 or if you want to resume old"
            " game type 2 and one more thing you can always UNDO by typing wrong starting index : ";
    int a;
    do {
        cin >> a;
        if(a == 1)
        {
            startGame();
            break;
        }
        else if(a == 2)
        {
            char tu;
            B.loadFromFile2(tu);
            if(tu == 'W') { changeTurn(); }
            break;
        }
        else
            cout << "invalid input";

    }while(true);

}

void Chess::changeTurn() {
    if(turn == White)
        turn = Black;
    else
        turn = White;
}

void clearScreen() {
    system("clear");
}


void Chess::play() {
    do{
        int px,py;
        if(findPawn(px,py))
        {
            B.pawnPromotion(px,py,turn);
        }
        B.printBoard();
        if(checkMate())
        {
            cout << "CheckMate!";
            exit(0);
        }
        changeTurn();
        clearScreen();
        if (turn == White)
            cout << "White\n";
        else
            cout << "Black\n";
        do {
            do {
                if (isCheck())
                    cout << "Checked\n";
                cout << "Enter starting index: ";
                cin >> sx >> sy;
                if(!callUndo())
                {
                    B.loadFromFile();
                    B.printBoard();
                    changeTurn();
                    moves_history.pop_back();
                    if (turn == White)
                        cout << "White\n";
                    else
                        cout << "Black\n";
                }
            } while (!checkSrc());
            loadHighPath();
            updateBoard();
            cout << "Enter ending index: ";
            cin >> ex >> ey;
            if(!checkDest())
            {
                char t;
                B.loadFromFile2(t);
                changeTurn();
                B.printBoard();
                moves_history.push_back(in);
                if (turn == White)
                    cout << "White\n";
                else
                    cout << "Black\n";
            }
        } while (!checkDest());
        while (selfCheck(sx, sy, ex, ey)) {
            cout << "Your in check\n";
            cout << "Enter starting index: ";
            cin >> sx >> sy;
            cout << "Enter ending index: ";
            cin >> ex >> ey;
        }
        B.writeToFile();
        if (turn == B.pieceAt(sx, sy)->getCol()  && checkMove() && (B.pieceAt(ex, ey) == nullptr || isKill())) {

            in.x = sx;
            in.y = sy;
            in.xx = ex;
            in.yy = ey;
            in.t = turn;
            moves_history.push_back(in);
            B.move(sx, sy, ex, ey);
        }
        else if(canCastle())
        {
            in.x = sx;
            in.y = sy;
            in.xx = ex;
            in.yy = ey;
            in.t = turn;
            moves_history.push_back(in);
            Castling();
        }
        B.writeToFile2(turn);
        if (checkMate())
        {
            B.printBoard();
            cout << "Checkmate!" << endl;
            printMovesHistory();
            showcheckMate();
        }
    }while(!checkMate() && !isStalemate());
}

bool Chess::isKill() {
    return B.pieceAt(ex,ey)->getCol() != B.pieceAt(sx,sy)->getCol();
}

void Chess::loadHighPath() {
    for(int i = 0;i < 8;i++)
    {
        for(int j = 0;j< 8;j++)
        {
            if(B.pieceAt(sx,sy)->isLegal(i,j))
                Hi[i][j] = true;
            else
                Hi[i][j] = false;
        }
    }
}

void Chess::updateBoard()
{
    for(int i =0;i < 8;i++)
    {
        for(int j =0;j<8;j++)
        {
            if(B.pieceAt(i,j) != nullptr)
                B.pieceAt(i,j)->print();
            else if (B.pieceAt(i,j) == nullptr && Hi[i][j])
                cout << "x";
            else
                cout << '-';
            cout << " ";
        }
        cout << endl;
    }

}

bool Chess::isCheck() {
    int kr,kc;
    findKing(kr,kc);
    changeTurn();
    for(int i = 0;i<8;i++)
    {
        for(int j = 0;j < 8;j++)
        {
            if(B.pieceAt(i,j) != nullptr && B.pieceAt(i,j)->isLegal(kr,kc) && B.pieceAt(i,j)->getCol() != B.pieceAt(kr,kc)->getCol()) {
                changeTurn();
                return true;
            }
        }
    }
    changeTurn();
    return false;
}

void Chess::findKing(int &x, int &y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if (B.pieceAt(i, j) != nullptr) {
                if (turn == B.pieceAt(i, j)->getCol()  && B.pieceAt(i, j)->getChar() == 'K') {
                    x = i;
                    y = j;
                    return;
                } else if (turn == B.pieceAt(i, j)->getCol() && B.pieceAt(i, j)->getChar() == 'k') {
                    x = i;
                    y = j;
                    return;
                }
            }
        }
    }
    x = -1;
    y = -1;
}


bool Chess::checkSrc() {
    return (sx >= 0 && sx < 8 && sy >= 0 && sy < 8 && B.pieceAt(sx,sy) != nullptr && B.pieceAt(sx,sy)->getCol() == turn);
}

bool Chess::checkDest() {
    return (ex >= 0 && ex < 8 && ey >= 0 && ey < 8 && B.pieceAt(sx,sy)->isLegal(ex,ey) && (!isCheck() || !selfCheck(sx,sy,ex,ey)));
}


bool Chess::selfCheck(int sr,int sc,int er,int ec) {
    Piece *St = B.pieceAt(sr, sc);
    Piece *Ed = B.pieceAt(er, ec);
    if(Ed != nullptr) {
        B.setPiece(sr, sc, nullptr);
        B.setPiece(er, ec, St);
    }
    else{
        B.setPiece(sr, sc, Ed);
        B.setPiece(er, ec, St);
    }

    if (isCheck()) {
        B.setPiece(sr, sc, St);
        B.setPiece(er, ec, Ed);

        return true;
    }

    B.setPiece(sr, sc, St);
    B.setPiece(er, ec, Ed);
    return false;
}

bool Chess::checkMate()
{
    changeTurn();
    if(isCheck())
    {
        int kr, kc;
        findKing(kr, kc);
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                for (int x = 0; x < 8; x++)
                {
                    for (int y = 0; y < 8; y++)
                    {
                        if (B.pieceAt(i, j) != nullptr)
                        {
                            if (B.pieceAt(i, j)->isLegal(x, y) && B.pieceAt(i, j)->getCol() == turn)
                            {
                                if (B.pieceAt(x, y) == nullptr || B.pieceAt(x, y)->getCol() != turn)
                                {
                                    if (!selfCheck(i, j, x, y))
                                    {
                                        changeTurn();
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        changeTurn();
        return true;
    }
    changeTurn();
    return false;
}


bool Chess::findPawn(int &px, int &py)
{
    for(int i = 0;i < 8;i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (B.pieceAt(i, j) != nullptr)
            {
                if (turn == B.pieceAt(i, j)->getCol() && (B.pieceAt(i, j)->getChar() == 'P' || B.pieceAt(i, j)->getChar() == 'p') && (i == 7 || i == 0))
                {
                    px = i;
                    py = j;
                    B.setPiece(px,py, nullptr);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Chess::canCastle() {
    if (sx == 0 && sy == 4 && B.pieceAt(sx, sy)->getCol() == Black && turn == Black && B.pieceAt(sx, sy)->getMoves() == 0) {
        if ((ex == 0 && ey == 0) && B.pieceAt(0, 0) != nullptr && B.pieceAt(0, 1) == nullptr && B.pieceAt(0, 2) == nullptr && B.pieceAt(0, 4) != nullptr && B.pieceAt(0, 3) == nullptr && B.pieceAt(0, 0)->getMoves() == 0) {
            return true;
        } else if ((ex == 0 && ey == 7) && B.pieceAt(0, 7) != nullptr && B.pieceAt(0, 6) == nullptr && B.pieceAt(0, 5) == nullptr && B.pieceAt(0, 4) != nullptr && B.pieceAt(0, 7)->getMoves() == 0) {
            return true;
        }
    } else if (sx == 7 && sy == 4 && B.pieceAt(sx, sy)->getCol() == White && turn == White && B.pieceAt(sx, sy)->getMoves() == 0) {
        if ((ex == 7 && ey == 0) && B.pieceAt(7, 0) != nullptr && B.pieceAt(7, 1) == nullptr && B.pieceAt(7, 2) == nullptr &&  B.pieceAt(7, 4) != nullptr && B.pieceAt(7, 3) == nullptr && B.pieceAt(7, 0)->getMoves() == 0) {
            return true;
        } else if ((ex == 7 && ey == 7) && B.pieceAt(7, 7) != nullptr && B.pieceAt(7, 6) == nullptr && B.pieceAt(7, 5) == nullptr && B.pieceAt(7, 4) != nullptr && B.pieceAt(7, 7)->getMoves() == 0) {
            return true;
        }
    }
    return false;
}

void Chess::Castling() {
    if (canCastle())
    {
        if (turn == White && sx == 7 && sy == 4)
        {
            if (ex == 7 && ey == 7)
            {
                B.move(7, 4, 7, 6);
                B.move(7, 7, 7, 5);
            }
            else if (ex == 7 && ey == 0)
            {
                B.move(7, 4, 7, 2);
                B.move(7, 0, 7, 3);
            }
        }
        else if (turn == Black && sx == 0 && sy == 4)
        {
            if (ex == 0 && ey == 7 )
            {
                B.move(0, 4, 0, 6);
                B.move(0, 7, 0, 5);
            }
            else if (ex == 0 && ey == 0)
            {
                B.move(0, 4, 0, 2);
                B.move(0, 0, 0, 3);
            }
        }
    }
}

bool Chess::callUndo() {
    return (sx >=0 && sx < 8 && sy >=0 && sy < 8);
}

bool Chess::isStalemate() {
    changeTurn();

    if (isCheck()) {
        changeTurn();
        return false;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++)
                {
                    if(B.pieceAt(i, j) != nullptr)
                    {
                        if(B.pieceAt(i, j)->isLegal(x, y) && B.pieceAt(i, j)->getCol() == turn)
                        {
                            if (B.pieceAt(x, y) == nullptr || B.pieceAt(x, y)->getCol() != turn) {
                                if (!selfCheck(i, j, x, y)) {
                                    changeTurn();
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    changeTurn();
    return true;
}

void Chess::printMovesHistory() {
    int i = 1;
    cout << "Moves History\n";
for(auto &moves: moves_history)
{
    cout << i++ << ". "<< moves.x << "," << moves.y << " to " << moves.xx << "," << moves.yy << " for ";
    if(moves.t == Black)
        cout << "Black.\n";
    else
        cout << "White.\n";
}
}

void Chess::showcheckMate() {
    B.deleteBoard();
B.InitializeBoard();
for(auto &a:moves_history)
{
    B.move(a.x,a.y,a.xx,a.yy);
    cout << "\n\n";
    B.printBoard();
    this_thread::sleep_for(chrono::seconds(2));
}
cout << "\nThat's how you got checkMate\n";
}










