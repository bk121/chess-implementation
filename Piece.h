#ifndef PIECE_H
#define PIECE_H

#include <string>

class ChessBoard;  

class Piece{
  std::string name;
  std::string colour;
 protected:
 ChessBoard* board; 
  // function takes in two position coordinates and attempts to find a diagonal path between
  // them, uninterrupted by pieces. If it succeeds, it returns true, otherwise false.
  bool diagonalPath(int start_row, int start_column, int end_row, int end_column);
  // function takes in two position coordinates and attempts to find a sideways path between
  // them, uninterrupted by pieces. If it succeeds, it returns true, otherwise false.
  bool sidewaysPath(int start_row, int start_column, int end_row, int end_column);
  // function returns true if the piece at end_row, end_column is the opposite colour to the 
  // piece at start_row, start_column.
  bool oppositeColourTaken(int start_row, int start_column, int end_row, int end_column);    
  
 public:
  Piece(std::string name, std::string colour, ChessBoard* board);
  // virtual function inherited and overriden by each of the subclasses to suit their particular
  // legal requirements for a move. If the move is legal, the function will return true, otherwise
  // false.
  virtual bool validateMove(int start_row, int start_column, int end_row, int end_column);
  std::string getName();
  std::string getColour();
};

#endif
