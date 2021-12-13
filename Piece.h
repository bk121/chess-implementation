#ifndef PIECE_H
#define PIECE_H

#include <string>


class Piece{
  std::string name;
  std::string colour;
 public:
  Piece(std::string name, std::string colour);
  virtual bool validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]);
  std::string getName();
  std::string getColour();

};

#endif
