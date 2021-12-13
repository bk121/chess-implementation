#ifndef PAWN_H
#define PAWN_H

#include <string>


class Pawn : public Piece{
 public:
  Pawn(std::string name, std::string colour);
  bool validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]);
};
  

#endif
