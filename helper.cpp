#include "helper.h"
#include "Piece.h"
#include "ChessBoard.h"
#include <string>
#include <iostream>

void makeIndices(std::string str, int& row, int& column){
  column=str[0]-ASCII_A;
  row=str[1]-ASCII_1;
}           
      
bool oneToEight(char ch){
  for (int i=0; i<8; i++){
    if (ch==i+ASCII_1){
      return true;
    }
  }
  return false;
}


bool aToH(char ch){
  for (int i=0; i<8; i++){
    if (ch==i+ASCII_A){
      return true;
    }
  }
  return false;
}
