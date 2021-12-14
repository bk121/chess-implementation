#ifndef HELPER_H
#define HELPER_H
#include <string>
#include "Piece.h"
#include "ChessBoard.h"

//Takes a chess-language position reference and sets the parameters row and column into the
//array indices this represents
void makeIndices(std::string str, int& row, int& column);           

// takes in a character and returns true if this is an integer between 1 and 8. Otherwise returns
// false.
bool oneToEight(char ch);

// takes in a character and returns true if this is a letter from A-H (uppercase). Otherwise returns
// false.
bool aToH(char ch);

#endif
