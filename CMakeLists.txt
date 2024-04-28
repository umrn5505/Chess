cmake_minimum_required(VERSION 3.27)
project(Chess)

set(CMAKE_CXX_STANDARD 23)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
find_package(Curses REQUIRED)

add_executable(Chess main.cpp
        Piece.cpp
        Piece.h
        Utility.h
        Board.cpp
        Board.h
        Pawn.cpp
        Pawn.h
        Rook.cpp
        Rook.h
        Bishop.cpp
        Bishop.h
        Knight.cpp
        Knight.h
        King.cpp
        King.h
        Queen.cpp
        Queen.h
        Bishop.cpp
        Chess.cpp
        Chess.h
)
target_link_libraries(Chess sfml-graphics ${CURSES_LIBRARIES})
