#ifndef PIECE_H
#define PIECE_H
#include <string>

class Piece{   
  public:        
    virtual char pieceEnum();        
    virtual std::string pieceAscii();  
  private:
    int colour;   
};

#endif