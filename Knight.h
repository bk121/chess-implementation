#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>

class Knight : public Piece{
  bool LShape(int start_row, int start_column, int end_row, int end_column);
public:
  Knight(std::string name, std::string colour, ChessBoard* board);
  bool validateMove(int start_row, int start_column, int end_row, int end_column);
};

#endif
