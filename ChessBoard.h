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

#define INCORRECT_INPUT_FORMAT 1
#define START_EQUALS_END 2
#define CASTLING 3

class ChessBoard {
  std::string current_colour = {"White"};
  Piece* configuration[8][8];
  int white_king_position[2]; 
  int black_king_position[2];
  // returns true if the king of the current_colour is in check, otherwise false.
  bool inCheck();
  // returns true if the square passed in is under attack by an opposing piece, otherwise false.
  bool squareInCheck(int row, int column);
  // returns true if the king of current_colour has been checkmated, otherwise false.
  bool checkmate();
  // moves the Piece* at (start_row, start_column) to (end_row, end_column), and returns the 
  // Piece* at (end_row, end_column) if there is one - otherwise nullptr is returned. Function
  // also updates white/black_king_position if he moves.
  Piece* move(int start_row, int start_column, int end_row, int end_column);
  // function takes in the strings for start and end position and then returns the macros 
  // INCORRECT_INPUT_FORMAT, START_EQUALS_END, CASTLING correspondingly.
  int checkInput(std::string start, std::string end);
  // special function that takes in kings position as 'start' and 0-0 for kingside or 0-0-0 for 
  // queenside as end. The function will then return true if the castling was successful, or false
  // if one or more conditions make the castling attempt illegal.
  bool castlingMove(std::string start, std::string end); 
  // these four variables are true until a move makes the castling type in question illegal - eg. 
  // if the white king moves then kingside_white and queenside_white will be false.
  bool kingside_white=true;
  bool queenside_white=true;
  bool kingside_black=true;
  bool queenside_black=true;
  // function sets current_colour's queenside boolean variable to false.
  void noQueenside();
  // function sets current_colour's kingside boolean variable to false.
  void noKingside();
  // function updates values of variables castle_row and castle_column to the square passed in
  // str.
  void setCastleSquare(std::string str, int& castle_row, int& castle_column);
  // variable set to true after a stalemate or checkmate.
  bool game_over=false;
  
 public:
  ChessBoard();
  ~ChessBoard();
  // function takes in a start and end position and attempts to make the move. If the move is 
  // legal, the function checks if the move leads to a check, checkmate, or stalemate.
  void submitMove(std::string start, std::string end);
  // function deletes any Pieces that have pointers on the current board and sets up new board.
  void resetBoard();
  Piece* (*getConfiguration())[8];
  Piece* getPiece(int row, int column);
  // function takes in king colour and returns an array of the king's row and column.
  int* getKingPosition(std::string kingColour);
  // function takes in king colour and updates white/black_king_position.
  void setKingPosition(std::string kingColour, int newRow, int newColumn);
  
};

#endif
