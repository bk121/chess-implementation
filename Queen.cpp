#include "Piece.h"
#include "Queen.h"
#include <string>
#include "helper.h"

Queen::Queen(std::string name, std::string colour) : Piece(name, colour){}

bool Queen::validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]){
    if (!sidewaysPath(start_row, start_column, end_row, end_column, configuration) 
                && !diagonalPath(start_row, start_column, end_row, end_column, configuration)){
        return false;
    }

    if (!oppositeColourTaken(start_row, start_column, end_row, end_column, configuration)){
        return false;
    }

    return true;
}
