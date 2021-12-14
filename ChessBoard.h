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

//so now can i use the chessboard* in my piece.cpp yep

class ChessBoard {
  std::string current_colour = {"White"};
  Piece* configuration[8][8];
  int whiteKingPosition[2]; //macros?
  int blackKingPosition[2];
  bool inCheck();
  bool checkmate();
  Piece* move(int start_row, int start_column, int end_row, int end_column);
  int checkInput(std::string start, std::string end);  
  
 public:
  ChessBoard();
  ~ChessBoard();
  void submitMove(std::string start, std::string end);
  void resetBoard();
  Piece* (*getConfiguration())[8];
  Piece* getPiece(int row, int column);
  int* getKingPosition(std::string kingColour);
  void setKingPosition(std::string kingColour, int newRow, int newColumn);
  
};

#endif
