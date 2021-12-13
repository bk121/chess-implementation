#include <string>
#include "Piece.h"
#include <iostream>

Piece::Piece(std::string name, std::string colour) : 
        name(name), colour(colour){}

bool Piece::validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]){
  std::cout << "Piece incorrectly assigned\n";
  return false;
}

std::string Piece::getName(){
  return name;
}

std::string Piece::getColour(){
  return colour;
}
