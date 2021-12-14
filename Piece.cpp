#include <string>
#include "Piece.h"
#include <iostream>
#include "ChessBoard.h" 

Piece::Piece(std::string name, std::string colour, ChessBoard* board) : 
        name(name), colour(colour), board(board){}

bool Piece::validateMove(int start_row, int start_column, int end_row, int end_column){
  std::cout << "Piece incorrectly assigned\n";
  return false;
}

std::string Piece::getName(){
  return name;
}

std::string Piece::getColour(){
  return colour;
}

bool Piece::diagonalPath(int start_row, int start_column, int end_row, int end_column){
  double gradient = static_cast<double>(end_column-start_column)/(end_row-start_row);
  if (!(gradient==1||gradient==-1)){
    return false;
  }
    int smaller_row = start_row<end_row? start_row:end_row;
    int greater_row = start_row>end_row? start_row:end_row;
    int smaller_column = start_column<end_column? start_column:end_column;
    int distance = greater_row-smaller_row;
  if (gradient==1){
    for (int i=1; i<distance; i++){
      if (board->getConfiguration()[smaller_row+i][smaller_column+i]!=nullptr){
        return false;
      }
    }
  }

   if (gradient==-1){ 
    for (int i=1; i<distance; i++){
      if (board->getConfiguration()[greater_row-i][smaller_column+i]!=nullptr){
        return false;
      }
    }
  } 
return true;
}

bool Piece::sidewaysPath(int start_row, int start_column, int end_row, int end_column){
  if (!(start_row==end_row || start_column==end_column)){
    return false;
  } 
 
  if (start_row==end_row){
    int smaller = start_column<end_column? start_column:end_column;
    int greater = start_column>end_column? start_column:end_column;
    for (int i= smaller+1; i<greater; i++){
      if (board->getConfiguration()[start_row][i]!=nullptr){
        return false;
      }
    }
  }

  if (start_column==end_column){
    int smaller = start_row<end_row? start_row:end_row;
    int greater = start_row>end_row? start_row:end_row; 
    for (int i= smaller+1; i<greater; i++){
      if (board->getConfiguration()[i][start_column]!=nullptr){
        return false;
      }
    }
  }
  return true;
}

bool Piece::oppositeColourTaken(int start_row, int start_column, int end_row, int end_column){
  if (board->getConfiguration()[end_row][end_column]==nullptr){
    return true;
  }
  if (board->getConfiguration()[start_row][start_column]->getColour()==board->getConfiguration()[end_row][end_column]->getColour()){
    return false;
  }
  return true;
}