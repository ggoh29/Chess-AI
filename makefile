# g++ -Wno-multichar chessBoard/board/*.cpp chessBoard/main.cpp chessBoard/pieces/*.cpp chessBoard/moves/*.cpp chessBoard/players/*.cpp -o main && ./main 

cd chessBoard; 
cmake -DCMAKE_PREFIX_PATH=~/libtorch
cmake --build . --config Release ; ./main
rm *.a
rm *Cache.txt
rm *.cmake
rm -rf CMakeFiles
shopt -u extglob