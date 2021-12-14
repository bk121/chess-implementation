#ifndef PAWN_H
#define PAWN_H

#include <string>
#include "Piece.h"

class Piece;

class Pawn : public Piece{
 public:
  Pawn(std::string name, std::string colour, ChessBoard* board);
  bool validateMove(int start_row, int start_column, int end_row, int end_column);
};
  

#endif
