#include "Piece.h"
#include "King.h"
#include <string>
#include "helper.h"

King::King(std::string name, std::string colour) : Piece(name, colour){}

bool King::validateMove(int start_row, int start_column, int end_row, int end_column, Piece* configuration [8][8]){
    if (!kingMove(start_row, start_column, end_row, end_column)){
        return false;
    }
    if (!oppositeColourTaken(start_row, start_column, end_row, end_column, configuration)){
        return false;
    }
    return true;
}