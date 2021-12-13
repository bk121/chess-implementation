#ifndef CASTLE_H
#define CASTLE_H

#include <string>

class Castle : public Piece{
public:
  Castle(std::string name, std::string colour);
  bool validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]);
};


#endif
