#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>

class Knight : public Piece{
public:
  Knight(std::string name, std::string colour);
  bool validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration [8][8]);
};

#endif
