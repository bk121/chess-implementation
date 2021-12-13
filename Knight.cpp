#include "Piece.h"
#include "Knight.h"
#include <string>
#include "helper.h"

Knight::Knight(std::string name, std::string colour) : Piece(name, colour){}

bool Knight::validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration[8][8]){
    if (!LShape(start_row, start_column, end_row, end_column)){
        return false;
    }
    if (!oppositeColourTaken(start_row, start_column, end_row, end_column, configuration)){
        return false;
    }
    return true;
}
