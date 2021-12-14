#include "Piece.h"
#include "King.h"
#include <string>
#include "helper.h"
#include "ChessBoard.h"

King::King(std::string name, std::string colour, ChessBoard* board) : Piece(name, colour, board){}

bool King::validateMove(int start_row, int start_column, int end_row, int end_column){
    if (!kingMove(start_row, start_column, end_row, end_column)){
        return false;
    }
    if (!oppositeColourTaken(start_row, start_column, end_row, end_column)){
        return false;
    }
    return true;
}

bool King::kingMove(int start_row, int start_column, int end_row, int end_column){
  if (start_row==end_row && (start_column+1==end_column || start_column-1==end_column)){
    return true;
  }
  if (start_row+1==end_row && (start_column==end_column || start_column+1==end_column || start_column-1==end_column)){
    return true;
  }
  if (start_row-1==end_row && (start_column==end_column || start_column+1==end_column || start_column-1==end_column)){
    return true;
  }
  return false;
}