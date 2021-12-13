#include "Piece.h"
#include "Pawn.h"
#include <string>

Pawn::Pawn(std::string name, std::string colour) : Piece(name, colour){}
bool Pawn::validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]){
  
  if (getColour() == "White"){
    if (start_column==end_column && start_row+1==end_row && configuration[end_row][end_column]==nullptr){
      return true;
    }
    if (start_column==end_column && start_row==1 && end_row==3 && configuration[end_row][end_column]==nullptr){
      return true;
    }
    if ((start_column+1==end_column || start_column-1==end_column) && start_row+1==end_row 
              && configuration[end_row][end_column]!=nullptr && configuration[end_row][end_column]->getColour()!=getColour()){
      return true;
    }
  }

  if (getColour() == "Black"){
    if (start_column==end_column && start_row-1==end_row && configuration[end_row][end_column]==nullptr){
      return true;
    }
    if (start_column==end_column && start_row==6 && end_row==4 && configuration[end_row][end_column]==nullptr){
      return true;
    }
    if ((start_column-1==end_column || start_column+1==end_column) && start_row-1==end_row 
              && configuration[end_row][end_column]!=nullptr && configuration[end_row][end_column]->getColour()!=getColour()){
      return true;
    }
  }
  return false;
}
