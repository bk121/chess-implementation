#ifndef HELPER_H
#define HELPER_H
#include <string>
#include "Piece.h"
#include "ChessBoard.h"

//Takes a chess-language position reference and sets the parameters row and column into the
//array indices this represents
void makeIndices(std::string str, int& row, int& column);           

bool oneToEight(char ch);

bool aToH(char ch);

#endif
