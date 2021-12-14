#include "Piece.h"
#include "Castle.h"
#include "helper.h"
#include <string>
#include "ChessBoard.h"

Castle::Castle(std::string name, std::string colour, ChessBoard* board) : Piece(name, colour, board){}

bool Castle::validateMove(int start_row, int start_column, int end_row, int end_column){
    if (!sidewaysPath(start_row, start_column, end_row, end_column)){
        return false; //for example I could jus thave sideways path here
    }
    if (!oppositeColourTaken(start_row, start_column, end_row, end_column)){
        return false; // ok but
    }
    return true;
}
