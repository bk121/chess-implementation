#include "helper.h"
#include "Piece.h"
#include "ChessBoard.h"
#include <string>
#include <iostream>

void makeIndices(std::string str, int& row, int& column){
  column=str[0]-65;
  row=str[1]-49;
}

bool diagonalPath(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]){
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
      if (configuration[smaller_row+i][smaller_column+i]!=nullptr){
        return false;
      }
    }
  }

   if (gradient==-1){ 
    for (int i=1; i<distance; i++){
      if (configuration[greater_row-i][smaller_column+i]!=nullptr){
        return false;
      }
    }
  } 
return true;
}

bool sidewaysPath(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]){
  
  
  if (!(start_row==end_row || start_column==end_column)){
    return false;
  }
 
  if (start_row==end_row){
    int smaller = start_column<end_column? start_column:end_column;
    int greater = start_column>end_column? start_column:end_column;
    for (int i= smaller+1; i<greater; i++){
      if (configuration[start_row][i]!=nullptr){
        return false;
      }
    }
  }

  if (start_column==end_column){
    int smaller = start_row<end_row? start_row:end_row;
    int greater = start_row>end_row? start_row:end_row; 
    for (int i= smaller+1; i<greater; i++){
      if (configuration[i][start_column]!=nullptr){
        return false;
      }
    }
  }
  return true;
}

bool oppositeColourTaken(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]){
  if (configuration[end_row][end_column]==nullptr){
    return true;
  }
  if (configuration[start_row][start_column]->getColour()==configuration[end_row][end_column]->getColour()){
    return false;
  }
  return true;
}

bool LShape(int start_row, int start_column, int end_row, int end_column){  
  if ((start_row+1==end_row || start_row-1==end_row) && (start_column+2==end_column || start_column-2==end_column)){
    return true;
  }
  if((start_row+2==end_row || start_row-2==end_row) && (start_column+1==end_column || start_column-1==end_column)){
    return true;
  }
  return false;
}

bool kingMove(int start_row, int start_column, int end_row, int end_column){
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

// takes in colour of king and his square to see if he is in check
bool inCheck(int kingRow, int kingColumn, Piece* configuration [8][8], std::string kingColour){
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      if (configuration[i][j]!=nullptr){
        if (kingColour!=configuration[i][j]->getColour()){
          if (configuration[i][j]->validateMove(i, j, kingRow, kingColumn, configuration)){
            return true;
          }
        }
      }
    }
  }
  return false;
}

bool checkmate(int kingRow, int kingColumn, Piece* configuration [8][8], std::string kingColour, ChessBoard* cb){
  Piece* tempDelete;
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      if (configuration[i][j]!=nullptr){
        if (kingColour==configuration[i][j]->getColour() && !(kingRow==i && kingColumn==j)){
          for (int k=0; k<8; k++){
            for (int l=0; l<8; l++){
              if (configuration[i][j]->validateMove(i, j, k, l, configuration)){
                Piece* tempDelete = cb->move(i, j, k, l);
                if (!inCheck( *(cb->getKingPosition(kingColour)) , *(cb->getKingPosition(kingColour)+1) , configuration, kingColour)){
                  cb->move(k, l, i, j);
                  configuration[k][l]=tempDelete;
                  return false;
                }
                cb->move(k, l, i, j);
                configuration[k][l]=tempDelete;
              }
            }
          }
        }
      }
    }
  }
  return true;
}   
      
      /*if (configuration[kingRow][kingColumn]->validateMove(kingRow, kingColumn, i, j, configuration)){
        tempDelete=move(kingRow, kingColumn, i, j, configuration);
        if (!inCheck(i, j, configuration, kingColour){
          move(i, j, kingRow, kingColumn, configuration);
          configuration[i][j]=tempDelete;
          return false;
        }
        move(i, j, kingRow, kingColumn, configuration);
        configuration[i][j]=tempDelete;
      }*/

      
