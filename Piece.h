#ifndef PIECE_H
#define PIECE_H

#include <string>

class ChessBoard;  

class Piece{
  std::string name;
  std::string colour;
 protected:
 ChessBoard* board; 
  bool diagonalPath(int start_row, int start_column, int end_row, int end_column);
  bool sidewaysPath(int start_row, int start_column, int end_row, int end_column);
  bool oppositeColourTaken(int start_row, int start_column, int end_row, int end_column);    
  
 public:
  Piece(std::string name, std::string colour, ChessBoard* board);
  virtual bool validateMove(int start_row, int start_column, int end_row, int end_column);
  std::string getName();
  std::string getColour();
};

#endif
