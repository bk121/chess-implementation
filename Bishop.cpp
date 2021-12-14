#include "Piece.h"
#include "Bishop.h"
#include "helper.h"
#include "ChessBoard.h"
#include <cstring>

Bishop::Bishop(std::string name, std::string colour, ChessBoard* board) : Piece(name, colour, board){}

bool Bishop::validateMove(int start_row, int start_column, int end_row, int end_column){
if (!diagonalPath(start_row, start_column, end_row, end_column)){
  return false;
}
if (!oppositeColourTaken(start_row, start_column, end_row, end_column)){
  return false;
}
return true;
}

