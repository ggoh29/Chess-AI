project(Chess-AI)

cmake_minimum_required(VERSION 3.2)
include(CTest)

add_subdirectory(../chessBoard)
add_library(BOARD ../chessBoard/Board.h ../chessBoard/Board.cpp)
find_library(PIECES NAMES dcmdata PATHS ../chessBoard/pieces)
add_executable(tester boardTests.cpp)

target_link_libraries(tester BOARD ${PIECES})

add_test(Tester tester)