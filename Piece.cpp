//
// Created by umer on 4/19/24.
//

#include "Piece.h"
#include "cmath"
#include "Board.h"


Piece::Piece(int x, int y, Board *b, Colour col,char s,int mv){
_x = x;
_y = y;
_b = b;
colour = col;
sym = s;
moveCounter = mv;
}

bool Piece::isHorizontalMove(int _x, int _y, int er, int ec) {
    return _x == er;
}

bool Piece::isVerticalMove(int _x, int _y, int er, int ec) {

    return _y == ec;
}

bool Piece::isDiagonalMove(int _x, int _y, int er, int ec) {
    int dr = _x - er;
    int dc = _y - ec;
    return abs(dr) == abs(dc);
}

bool Piece::isHorizontalClear(int _x, int _y, int er, int ec,Board *b) {
   if(_y > ec)
   {
       for(int i = ec+1;i < _y;i++)
       {
           if(b->pieceAt(_x,i) != nullptr)
           {
               return false;

           }
       }
       return true;
   }
   else
   {
       for(int i = _y + 1;i < ec;i++)
       {
           if(b->pieceAt(_x,i) != nullptr)
           {
               return false;

           }
       }
       return true;
   }
}

bool Piece::isVerticalClear(int _x, int _y, int er, int ec, Board *b) {
    if(_x > er)
    {
        for(int i = er+1;i < _x;i++)
        {
            if(b->pieceAt(i,_y) != nullptr)
            {
                return false;

            }
        }
        return true;
    }
    else
    {
        for(int i = _x + 1;i < er;i++)
        {
            if(b->pieceAt(i,_y) != nullptr)
            {
                return false;
            }
        }
        return true;
    }
}

bool Piece::isDiagonalClear(int _x, int _y, int er, int ec, Board *b) {
    int dr = _x - er;
    int dc = _y - ec;
    if(dr < 0 && dc < 0)
    {
        for(int i = 1 ;i < abs(dr);i++)
        {
            if(b->pieceAt(_x+i,_y+i)!= nullptr)
                return false;
        }
        return true;
    }
    else if(dr<0 && dc > 0)
    {
        for(int i = 1;i<abs(dr);i++)
        {
            if(b->pieceAt(_x+i,_y-i)!= nullptr)
                return false;
        }
        return true;
    }
    else if(dr > 0 && dc < 0)
    {
        for(int i = 1;i<abs(dr);i++) {
            if (b->pieceAt(_x-i,_y+i)!= nullptr)
                return false;
        }
        return true;
    }
    else if(dr > 0 && dc > 0)
    {
        for(int i = 1;i < abs(dr);i++)
        {
            if (b->pieceAt(_x-i, _y-i) != nullptr)
                return false;
        }
        return true;
    }
    return true;
}

void Piece::move(int nr, int nc) {
_x = nr;
_y = nc;
}








