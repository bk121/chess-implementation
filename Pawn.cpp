#include "Piece.h"
#include "Pawn.h"
#include "ChessBoard.h"
#include <string>

Pawn::Pawn(std::string name, std::string colour, ChessBoard* board) : Piece(name, colour, board){}
bool Pawn::validateMove(int start_row, int start_column, int end_row, int end_column){

  if (getColour() == "White"){
    if (start_column==end_column && start_row+1==end_row && board->getConfiguration()[end_row][end_column]==nullptr){
      return true;
    }
    if (start_column==end_column && start_row==1 && end_row==3 && board->getConfiguration()[end_row][end_column]==nullptr && board->getConfiguration()[2][start_column]==nullptr){
      return true;
    }
    if ((start_column+1==end_column || start_column-1==end_column) && start_row+1==end_row 
              && board->getConfiguration()[end_row][end_column]!=nullptr && board->getConfiguration()[end_row][end_column]->getColour()!=getColour()){
      return true;
    }
  }

  if (getColour() == "Black"){
    if (start_column==end_column && start_row-1==end_row && board->getConfiguration()[end_row][end_column]==nullptr){
      return true;
    }
    if (start_column==end_column && start_row==6 && end_row==4 && board->getConfiguration()[end_row][end_column]==nullptr && board->getConfiguration()[5][start_column]==nullptr){
      return true;
    }
    if ((start_column-1==end_column || start_column+1==end_column) && start_row-1==end_row 
              && board->getConfiguration()[end_row][end_column]!=nullptr && board->getConfiguration()[end_row][end_column]->getColour()!=getColour()){
      return true;
    }
  }
  return false;
}
