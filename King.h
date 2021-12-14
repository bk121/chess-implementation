#ifndef KING_H
#define KING_H

#include <string>

class King : public Piece{
  bool kingMove(int start_row, int start_column, int end_row, int end_column);
public:
  King(std::string name, std::string colour, ChessBoard* board);
  bool validateMove(int start_row, int start_column, int end_row, int end_column);

};

#endif
