#ifndef KING_H
#define KING_H

#include <string>

class King : public Piece{
public:
  King(std::string name, std::string colour);
  bool validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration [8][8]);
};

#endif
