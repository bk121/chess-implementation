#include <iostream>
#include <string>
#include "ChessBoard.h"
#include "helper.h"

ChessBoard::ChessBoard(){
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      configuration[i][j]=nullptr;
    }
  }
  resetBoard();
  }

Piece* const & ChessBoard::getConfiguration(){
  return configuration[0][0];
}

void ChessBoard::resetBoard(){
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      if (configuration[i][j]!=nullptr){
      delete configuration[i][j];
      }
    }
  }
  //set empty squares and pawns
  for (int i=0; i<8; i++){
    Pawn* ptr=new Pawn("Pawn", "White");
    configuration[1][i]=ptr;
    configuration[6][i]= new Pawn("Pawn", "Black");
    for (int j=2; j<6; j++){
      configuration[j][i]=nullptr;
    }
  }
  
  // set other pieces
  configuration [0][0]=new Castle("Castle", "White");
  configuration [0][1]=new Knight("Knight", "White");
  configuration [0][2]=new Bishop("Bishop", "White");
  configuration [0][3]=new Queen("Queen", "White");
  configuration [0][4]=new King("King", "White");
  configuration [0][5]=new Bishop("Bishop", "White");
  configuration [0][6]=new Knight("Knight", "White");
  configuration [0][7]=new Castle("Castle", "White");
  
  configuration [7][0]=new Castle("Castle", "Black");
  configuration [7][1]=new Knight("Knight", "Black");
  configuration [7][2]=new Bishop("Bishop", "Black");
  configuration [7][3]=new Queen("Queen", "Black");
  configuration [7][4]=new King("King", "Black");
  configuration [7][5]=new Bishop("Bishop", "Black");
  configuration [7][6]=new Knight("Knight", "Black");
  configuration [7][7]=new Castle("Castle", "Black");
  
  current_colour="White";
  whiteKingPosition[0]=0;
  whiteKingPosition[1]=4;
  blackKingPosition[0]=7; 
  blackKingPosition[1]=4;

  std::cout << "A new chess game is started!\n";
}
void ChessBoard::submitMove(std::string start, std::string end){
  int start_row;
  int start_column;
  int end_row;
  int end_column;
  makeIndices(start, start_row, start_column);
  makeIndices(end, end_row, end_column);
  
  if (getPiece(start_row, start_column)==nullptr){
    std::cout << "There is no piece at position " << start << "!\n";
    return;
  }

  Piece* piece = getPiece(start_row, start_column);

  //wrong colour
  if (piece->getColour()!=current_colour){
    std::cout << "It is not " << piece->getColour() << "'s turn to move!\n";
    return;
  }

  //legal piece moves
  if (piece->validateMove(start_row, start_column, end_row, end_column, configuration)==false){
    std::cout << piece->getColour() << "'s " << piece->getName()
	            << " cannot move to " << end << "!\n";
    return;
  }

  Piece* takenPiece=move(start_row, start_column, end_row, end_column);

  //does move leave own king in check
  int kingRow=*(getKingPosition(current_colour));
  int kingColumn=*(getKingPosition(current_colour)+1);
  if(inCheck(kingRow, kingColumn, configuration, current_colour)){
    std::cout << piece->getColour() << "'s " << piece->getName()
	            << " cannot move to " << end << " because it leaves their king in check!\n";
    move(end_row, end_column, start_row, start_column);
    configuration[end_row][end_column]=takenPiece;
    return;
  }

  //move output
  if (takenPiece == nullptr){ 
    std::cout << current_colour << "'s " << piece->getName() << " moves from " << start << " to "
      << end << std::endl;
  }
  else {
    std::cout << current_colour << "'s " << piece->getName() << " moves from " << start << " to "
      << end << " taking " << (current_colour=="White"? "Black's ":"White's ")
      << takenPiece->getName() << std::endl;
    delete takenPiece;
  }

  //switch colours
  if (current_colour=="White"){
    current_colour="Black";
  }
  else {
    current_colour="White";
  }
  //scan for possible check/checkmate on opponent's king
  kingRow=*(getKingPosition(current_colour));
  //std::cout << kingRow << "\n";
  kingColumn=*(getKingPosition(current_colour)+1);
  //std:: cout << kingColumn;
  
  if (inCheck(kingRow, kingColumn, configuration, current_colour)){
    if (checkmate(kingRow, kingColumn, configuration, current_colour, this)){
      std::cout << current_colour << " is in checkmate\n";
      return;
    }
    std::cout << current_colour << " is in check\n";
    return;
  }
  if (checkmate(kingRow, kingColumn, configuration, current_colour, this)){
    std::cout << current_colour << " cannot make a legal move. Game ends in stalemate.";
    return;
  }
  return;
}




Piece* ChessBoard::getPiece(int row, int column){
  return configuration[row][column];
  }

int* ChessBoard::getKingPosition(std::string kingColour){
  if (kingColour=="White"){
    return whiteKingPosition;
  }
  return blackKingPosition;
}
void ChessBoard::setKingPosition(std::string kingColour, int newRow, int newColumn){
  if (kingColour=="White"){
    whiteKingPosition[0]=newRow;
    whiteKingPosition[1]=newColumn;
  }
  else {
    blackKingPosition[0]=newRow;
    blackKingPosition[1]=newColumn;
  }
}

Piece* ChessBoard::move(int start_row, int start_column, int end_row, int end_column){
  //update king's position if necessary
  if (configuration[start_row][start_column]->getName()=="King"){
    setKingPosition(configuration[start_row][start_column]->getColour(), end_row, end_column);
  }
  Piece* takenPiece=configuration[end_row][end_column];
  configuration[end_row][end_column]=configuration[start_row][start_column];
  configuration[start_row][start_column]=nullptr;
  return takenPiece;
}

int ChessBoard::validateMove(Piece* piece){  
  return 0;
}
