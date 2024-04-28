// main.cpp
#include "Chess.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

const int boardSize = 8; // Chess board is 8x8
const int squareSize = 90;

int main() {
//    sf::Texture whitePawnTexture, whiteRookTexture, whiteKnightTexture, whiteBishopTexture, whiteQueenTexture, whiteKingTexture;
//    sf::Texture blackPawnTexture, blackRookTexture, blackKnightTexture, blackBishopTexture, blackQueenTexture, blackKingTexture;
    Chess game;
    game.play();
//    sf::RenderWindow window(sf::VideoMode(boardSize * squareSize, boardSize * squareSize), "Chess Board");
//    game.createBoard(window);
    return 0;
}
