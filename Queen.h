#ifndef QUEEN_H
#define QUEEN_H

#include <string>


class Queen : public Piece{
public:
  Queen(std::string name, std::string colour);
  bool validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]);
};

#endif
