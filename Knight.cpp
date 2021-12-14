#include "Piece.h"
#include "Knight.h"
#include <string>
#include "helper.h"

Knight::Knight(std::string name, std::string colour, ChessBoard* board) : Piece(name, colour, board){}

bool Knight::validateMove(int start_row, int start_column, int end_row, int end_column){
    if (!LShape(start_row, start_column, end_row, end_column)){
        return false;
    }
    if (!oppositeColourTaken(start_row, start_column, end_row, end_column)){
        return false;
    }
    return true;
}

bool Knight::LShape(int start_row, int start_column, int end_row, int end_column){ 
  if ((start_row+1==end_row || start_row-1==end_row) && (start_column+2==end_column || start_column-2==end_column)){
    return true;
  }
  if((start_row+2==end_row || start_row-2==end_row) && (start_column+1==end_column || start_column-1==end_column)){
    return true;
  }
  return false;
}
 