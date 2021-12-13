#ifndef HELPER_H
#define HELPER_H
#include <string>
#include "Piece.h"
#include "ChessBoard.h"

//Takes a chess-language position reference and sets the parameters row and column into the
//array indices this represents
void makeIndices(std::string str, int& row, int& column);

bool diagonalPath(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]);

bool sidewaysPath(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]);

bool oppositeColourTaken(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]);

bool LShape(int start_row, int start_column, int end_row, int end_column);

bool kingMove(int start_row, int start_column, int end_row, int end_column);

bool inCheck(int kingRow, int kingColumn, Piece* configuration [8][8], std::string kingColour);

bool checkmate(int kingRow, int kingColumn, Piece* configuration [8][8], std::string kingColour, ChessBoard* cb);

#endif
