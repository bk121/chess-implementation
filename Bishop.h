#ifndef BISHOP_H
#define BISHOP_H

#include <string>

class Bishop : public Piece{
public:
  Bishop(std::string name, std::string colour);
  virtual bool validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]);
};

#endif
