#include "Piece.h"
#include "Bishop.h"
#include "helper.h"
#include <cstring>

Bishop::Bishop(std::string name, std::string colour) : Piece(name, colour){}

bool Bishop::validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]){
if (!diagonalPath(start_row, start_column, end_row, end_column, configuration)){
  return false;
}
if (!oppositeColourTaken(start_row, start_column, end_row, end_column, configuration)){
  return false;
}
return true;
}

