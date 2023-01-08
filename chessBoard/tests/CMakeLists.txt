project(Chess-AI)

cmake_minimum_required(VERSION 3.2)
include(CTest)

# add_subdirectory(../chessBoard)
enable_testing()
add_executable(boardTests boardTests.cpp)
add_library(BOARD ../Board.h ../Board.cpp)
add_library(BISHOP ../pieces/Bishop.h ../pieces/Bishop.cpp)
add_library(KING ../pieces/King.h ../pieces/King.cpp)
add_library(QUEEN ../pieces/Queen.h ../pieces/Queen.cpp)
add_library(ROOK ../pieces/Rook.h ../pieces/Rook.cpp)
add_library(KNIGHT ../pieces/Knight.h ../pieces/Knight.cpp)
add_library(PAWN ../pieces/Pawn.h ../pieces/Pawn.cpp)
add_library(PIECE ../pieces/Piece.h ../pieces/Piece.cpp)

target_link_libraries(boardTests BOARD PIECE PAWN KNIGHT BISHOP ROOK QUEEN KING)

add_test(BOARDTESTS boardTests)