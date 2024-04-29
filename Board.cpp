//
// Created by umer on 4/19/24.
//

#include "Board.h"
#include <iostream>
#include <fstream>
using namespace std;
void Board::InitializeBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 1)
            {
                Bs[i][j] = new Pawn(i, j, this, Black,'p',0);
            }
            else if (i == 6)
            {
                Bs[i][j] = new Pawn(i, j, this, White,'P',0);
            }
            else if ((i == 0) && (j == 0 || j == 7))
            {
                Bs[i][j] = new Rook(i, j, this, Black,'r',0);
            }
            else if ((i == 7) && (j == 0 || j == 7))
            {
                Bs[i][j] = new Rook(i, j, this, White,'R',0);
            }
            else if ((i == 0) && (j == 1 || j == 6))
            {
                Bs[i][j] = new Knight(i, j, this, Black,'h',0);
            }
            else if ((i == 7) && (j == 1 || j == 6))
            {
                Bs[i][j] = new Knight(i, j, this, White,'H',0);
            }
            else if ((i == 0) && (j == 2 || j == 5))
            {
                Bs[i][j] = new Bishop(i, j, this, Black,'b',0);
            }
            else if ((i == 7) && (j == 2 || j == 5))
            {
                Bs[i][j] = new Bishop(i, j, this, White,'B',0);
            }
            else if ((i == 0) && (j == 3))
            {
                Bs[i][j] = new Queen(i, j, this, Black,'q',0);
            }
            else if ((i == 7) && (j == 3))
            {
                Bs[i][j] = new Queen(i, j, this, White,'Q',0);
            }
            else if ((i == 0) && (j == 4))
            {
                Bs[i][j] = new King(i, j, this, Black,'k',0);
            }
            else if ((i == 7) && (j == 4))
            {
                Bs[i][j] = new King(i, j, this, White,'K',0);
            }
        }
    }
}

void Board::printBoard()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if (Bs[i][j] != nullptr)
            {
                Bs[i][j]->print();
            }
            else
            {
                cout << "-";
            }
            cout << " ";
        }
        cout << endl;
    }
}

Piece *Board::pieceAt(int x, int y) {
    if(Bs[x][y] != nullptr)
       return Bs[x][y];
    else
        return nullptr;
}

void Board::move(int r, int c, int er, int ec) {
    if(Bs[r][c] != nullptr) {
        Bs[r][c]->setMoves();
        Bs[r][c]->move(er, ec);
        Bs[er][ec] = Bs[r][c];
        Bs[r][c] = nullptr;
    }
}

bool Board::isPawnKill(int er, int ec,Colour col) {
    return (Bs[er][ec] != nullptr && Bs[er][ec]->getCol() != col);
}

void Board::setPiece(int x, int y, Piece *A) {
    if (A != nullptr) {
        Bs[x][y] = A;
        Bs[x][y]->move(x, y);
    }
    else
        Bs[x][y] = A;
}

void Board::pawnPromotion(int x, int y, Colour col) {
    char opt;
    cout << "Enter the piece you want to promote your pawn to:\n"
         << "1. (Q)ueen 2. (R)ook 3. (K)night 4. (B)ishop: ";
    cin >> opt;
    switch (opt) {
        case 'Q':
        case 'q':
            if (col == White) {
                Bs[x][y] = new Queen(x, y, this, White, 'Q',0);
            } else {
                Bs[x][y] = new Queen(x, y, this, Black, 'q',0);
            }
            break;
        case 'R':
        case 'r':
            if (col == White) {
                Bs[x][y] = new Rook(x, y, this, White, 'R',0);
            } else {
                Bs[x][y] = new Rook(x, y, this, Black, 'r',0);
            }
            break;
        case 'K':
        case 'k':
            if (col == White) {
                Bs[x][y] = new Knight(x, y, this, White, 'H',0);
            } else {
                Bs[x][y] = new Knight(x, y, this, Black, 'h',0);
            }
            break;
        case 'B':
        case 'b':
            if (col == White) {
                Bs[x][y] = new Bishop(x, y, this, White, 'B',0);
            } else {
                Bs[x][y] = new Bishop(x, y, this, Black, 'b',0);
            }
            break;
        default:
            cout << "Invalid option! Please choose again." << endl;
            break;
    }
}

void Board::writeToFile() {
    ofstream wrt("../board.txt", ios::trunc);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Bs[i][j] != nullptr)
            {
                if (Bs[i][j]->getChar() == 'K') {
                    wrt << 'K';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'k') {
                    wrt << 'k';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'R') {
                    wrt << 'R';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'r') {
                    wrt << 'r';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'P') {
                    wrt << 'P';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'p') {
                    wrt << 'p';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'Q') {
                    wrt << 'Q';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'q') {
                    wrt << 'q';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'B') {
                    wrt << 'B';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'b') {
                    wrt << 'b';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'H') {
                    wrt << 'H';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'h') {
                    wrt << 'h';
                    wrt << Bs[i][j]->getMoves();
                }
            } else {
                wrt << 'N';
            }
        }
    }
    wrt.close();
}

void Board::loadFromFile() {
    ifstream rdr("../board.txt");
    char ch;
    for(int i = 0;i< 8;i++)
    {
        for(int j = 0;j <8 ;j++)
        {
            rdr >> ch;
            int mv;
            if(ch != 'N')
            {

                rdr >> mv;
                if(mv > 0){ mv--; }
            }
            Bs[i][j] = nullptr;
            if (ch == 'K') {
                Bs[i][j] = new King(i, j, this, White, 'K', mv);
            } else if (ch == 'k') {
                Bs[i][j] = new King(i, j, this, Black, 'k', mv);
            } else if (ch == 'R') {
                Bs[i][j] = new Rook(i, j, this, White, 'R', mv);
            } else if (ch == 'r') {
                Bs[i][j] = new Rook(i, j, this, Black, 'r', mv);
            } else if (ch == 'P') {
                Bs[i][j] = new Pawn(i, j, this, White, 'P', mv);
            } else if (ch == 'p') {
                Bs[i][j] = new Pawn(i, j, this, Black, 'p', mv);
            } else if (ch == 'Q') {
                Bs[i][j] = new Queen(i, j, this, White, 'Q', mv);
            } else if (ch == 'q') {
                Bs[i][j] = new Queen(i, j, this, Black, 'q', mv);
            } else if (ch == 'B') {
                Bs[i][j] = new Bishop(i, j, this, White, 'B', mv);
            } else if (ch == 'b') {
                Bs[i][j] = new Bishop(i, j, this, Black, 'b', mv);
            } else if (ch == 'H') {
                Bs[i][j] = new Knight(i, j, this, White, 'H', mv);
            } else if (ch == 'h') {
                Bs[i][j] = new Knight(i, j, this, Black, 'h', mv);
            } else if (ch == 'N'){
                Bs[i][j] = nullptr;
            }
        }
    }
}

void Board::writeToFile2(Colour t) {
    ofstream wrt("../board2.txt", ios::trunc);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Bs[i][j] != nullptr)
            {
                if (Bs[i][j]->getChar() == 'K') {
                    wrt << 'K';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'k') {
                    wrt << 'k';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'R') {
                    wrt << 'R';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'r') {
                    wrt << 'r';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'P') {
                    wrt << 'P';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'p') {
                    wrt << 'p';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'Q') {
                    wrt << 'Q';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'q') {
                    wrt << 'q';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'B') {
                    wrt << 'B';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'b') {
                    wrt << 'b';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'H') {
                    wrt << 'H';
                    wrt << Bs[i][j]->getMoves();
                }
                else if (Bs[i][j]->getChar() == 'h') {
                    wrt << 'h';
                    wrt << Bs[i][j]->getMoves();
                }
            } else {
                wrt << 'N';
            }
        }
    }
    if(t == White)
        wrt << 'W';
    else
        wrt << 'A';
}

void Board::loadFromFile2(char& col) {
    ifstream rdr("../board2.txt");
    char ch;
    for(int i = 0;i< 8;i++)
    {
        for(int j = 0;j <8 ;j++)
        {
            rdr >> ch;
            int mv;
            if(ch != 'N')
            {

                rdr >> mv;
                if(mv > 0){ mv--; }
            }
            Bs[i][j] = nullptr;
            if (ch == 'K') {
                Bs[i][j] = new King(i, j, this, White, 'K', mv);
            } else if (ch == 'k') {
                Bs[i][j] = new King(i, j, this, Black, 'k', mv);
            } else if (ch == 'R') {
                Bs[i][j] = new Rook(i, j, this, White, 'R', mv);
            } else if (ch == 'r') {
                Bs[i][j] = new Rook(i, j, this, Black, 'r', mv);
            } else if (ch == 'P') {
                Bs[i][j] = new Pawn(i, j, this, White, 'P', mv);
            } else if (ch == 'p') {
                Bs[i][j] = new Pawn(i, j, this, Black, 'p', mv);
            } else if (ch == 'Q') {
                Bs[i][j] = new Queen(i, j, this, White, 'Q', mv);
            } else if (ch == 'q') {
                Bs[i][j] = new Queen(i, j, this, Black, 'q', mv);
            } else if (ch == 'B') {
                Bs[i][j] = new Bishop(i, j, this, White, 'B', mv);
            } else if (ch == 'b') {
                Bs[i][j] = new Bishop(i, j, this, Black, 'b', mv);
            } else if (ch == 'H') {
                Bs[i][j] = new Knight(i, j, this, White, 'H', mv);
            } else if (ch == 'h') {
                Bs[i][j] = new Knight(i, j, this, Black, 'h', mv);
            } else if (ch == 'N'){
                Bs[i][j] = nullptr;
            }
        }
    }
    rdr >> col;
}



