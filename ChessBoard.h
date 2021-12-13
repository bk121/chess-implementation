#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Castle.h"


class ChessBoard {
  std::string current_colour = {"White"};
  Piece* configuration[8][8];
  int whiteKingPosition[2]; //macros?
  int blackKingPosition[2];
  
 public:
  ChessBoard();
  void submitMove(std::string start, std::string end);
  void resetBoard();
  Piece* const & getConfiguration();
  Piece* getPiece(int row, int column);
  int* getKingPosition(std::string kingColour);
  void setKingPosition(std::string kingColour, int newRow, int newColumn);
  Piece* move(int start_row, int start_column, int end_row, int end_column);
  int validateMove(Piece* piece);
};

#endif
