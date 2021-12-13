#include "Piece.h"
#include "Castle.h"
#include "helper.h"
#include <string>

Castle::Castle(std::string name, std::string colour) : Piece(name, colour){}

bool Castle::validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]){
    if (!sidewaysPath(start_row, start_column, end_row, end_column, configuration)){
        return false;
    }
    if (!oppositeColourTaken(start_row, start_column, end_row, end_column, configuration)){
        return false;
    }
    return true;
}
