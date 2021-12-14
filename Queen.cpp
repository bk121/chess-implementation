#include "Piece.h"
#include "Queen.h"
#include <string>
#include "helper.h"
#include "ChessBoard.h"

Queen::Queen(std::string name, std::string colour, ChessBoard* board) : Piece(name, colour, board){}

bool Queen::validateMove(int start_row, int start_column, int end_row, int end_column){
    if (!sidewaysPath(start_row, start_column, end_row, end_column) 
                && !diagonalPath(start_row, start_column, end_row, end_column)){
        return false;
    }

    if (!oppositeColourTaken(start_row, start_column, end_row, end_column)){
        return false;
    }

    return true;
}
