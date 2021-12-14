#include "helper.h"
#include "Piece.h"
#include "ChessBoard.h"
#include <string>
#include <iostream>

void makeIndices(std::string str, int& row, int& column){
  column=str[0]-65;
  row=str[1]-49;
}           
      
bool oneToEight(char ch){
  for (int i=0; i<8; i++){
    if (ch==i+49){
      return true;
    }
  }
  return false;
}


bool aToH(char ch){
  for (int i=0; i<8; i++){
    if (ch==i+65){
      return true;
    }
  }
  return false;
}
