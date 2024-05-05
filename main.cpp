// main.cpp
#include "Chess.h"
#include <SFML/Graphics.hpp>
using namespace std;


const int boardSize = 8; // Chess board is 8x8
const int squareSize = 100; // Increase square size for larger board and window

int main() {
    Chess game;
//    sf::RenderWindow window(sf::VideoMode(boardSize * squareSize, boardSize * squareSize), "Chess Board");
//    game.createBoard(window);
game.play();
    return 0;
}
