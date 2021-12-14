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

ChessBoard::~ChessBoard(){
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      if (configuration[i][j]!=nullptr){
      delete configuration[i][j];
      }
    }
  }
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
    configuration[1][i]= new Pawn("Pawn", "White", this);
    configuration[6][i]= new Pawn("Pawn", "Black", this);
    for (int j=2; j<6; j++){
      configuration[j][i]=nullptr;
    }
  }
  
  // set other pieces
  configuration [0][0]=new Castle("Castle", "White", this);
  configuration [0][1]=new Knight("Knight", "White", this);
  configuration [0][2]=new Bishop("Bishop", "White", this);
  configuration [0][3]=new Queen("Queen", "White", this);
  configuration [0][4]=new King("King", "White", this);
  configuration [0][5]=new Bishop("Bishop", "White", this);
  configuration [0][6]=new Knight("Knight", "White", this);
  configuration [0][7]=new Castle("Castle", "White", this);
  
  configuration [7][0]=new Castle("Castle", "Black", this);
  configuration [7][1]=new Knight("Knight", "Black", this);
  configuration [7][2]=new Bishop("Bishop", "Black", this);
  configuration [7][3]=new Queen("Queen", "Black", this);
  configuration [7][4]=new King("King", "Black", this);
  configuration [7][5]=new Bishop("Bishop", "Black", this);
  configuration [7][6]=new Knight("Knight", "Black", this);
  configuration [7][7]=new Castle("Castle", "Black", this);
  
  current_colour="White";
  whiteKingPosition[0]=0;
  whiteKingPosition[1]=4;
  blackKingPosition[0]=7; 
  blackKingPosition[1]=4;

  std::cout << "A new chess game is started!\n";
}


void ChessBoard::submitMove(std::string start, std::string end){

  
  if(game_over==true){
    std::cout << "Please reset board.\n";
    return;
  }

  switch (checkInput(start, end)){
    case 1:
      std::cout << "Input invalid - 'start position' and 'end position' must contain an uppercase letter\n"
                  "between A and H followed by an integer between 1 and 8. For castling, 'start position'\n" 
                  "is the king's position and 'end position' is '0-0' for kingside or '0-0-0' for queenside.\n";
      exit(1);
  
    case 2:
      std::cout << "'start position' and 'end position' cannot be the same.\n";
      exit(1);

    case 3:
      if (castlingMove(start, end)==false){
        std::cout << "Castling only allowed if the king and the castle have never moved, the squares between the\n"
                     "king and the castle are unoccupied, the king is not in check, and the king does not cross\n" 
                     "over or end on a square attacked by an enemy piece.\n";
      }
      return;
  }
    

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
  if (piece->validateMove(start_row, start_column, end_row, end_column)==false){
    std::cout << piece->getColour() << "'s " << piece->getName()
	            << " cannot move to " << end << "!\n";
    return;
  }

  Piece* takenPiece=move(start_row, start_column, end_row, end_column);

  //does move leave own king in check
  
  if(inCheck()){
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

  //check if castling information needs updating
  if (start=="E1"||start=="E8"){
    noKingside();
    noQueenside();
  }
  if (start=="A1"||start=="A8"){
    noQueenside();
  }
  if (start=="H1"||start=="H8"){
    noKingside();
  }
 
  //switch colours
  if (current_colour=="White"){
    current_colour="Black";
  }
  else {
    current_colour="White";
  }
  //scan for possible check/checkmate/stalemate 
  
  
  if (inCheck()){
    if (checkmate()){
      std::cout << current_colour << " is in checkmate\n";
      game_over=true;
      return;
    }
    std::cout << current_colour << " is in check\n";
    return;
  }


  if (checkmate()){
    std::cout << current_colour << " cannot make a legal move. Game ends in stalemate.\n";
    game_over=true;
    return;
  }

  return;
}


Piece* ChessBoard::getPiece(int row, int column){
  return configuration[row][column];
  }

Piece* (*ChessBoard::getConfiguration())[8]{
  return configuration;
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



// takes in colour of king and his square to see if he is in check
bool ChessBoard::inCheck(){
  int kingRow=*(getKingPosition(current_colour));
  int kingColumn=*(getKingPosition(current_colour)+1);
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      if (configuration[i][j]!=nullptr){
        if (current_colour!=configuration[i][j]->getColour()){
          if (configuration[i][j]->validateMove(i, j, kingRow, kingColumn)){
            return true;
          }
        }
      }
    }
  }
  return false;
}

bool ChessBoard::checkmate(){
  int kingRow=*(getKingPosition(current_colour));
  //std::cout << kingRow << "\n";
  int kingColumn=*(getKingPosition(current_colour)+1);
  //std:: cout << kingColumn;
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      if (configuration[i][j]!=nullptr){
        if (configuration[i][j]->getColour()==current_colour && !(kingRow==i && kingColumn==j)){
          for (int k=0; k<8; k++){
            for (int l=0; l<8; l++){
              if (configuration[i][j]->validateMove(i, j, k, l)){
                Piece* tempDelete = move(i, j, k, l);
                if (!inCheck()){
                  move(k, l, i, j);
                  configuration[k][l]=tempDelete;
                  return false;
                }
                move(k, l, i, j);
                configuration[k][l]=tempDelete;
              }
            }
          }
        }
      }
    }
  }
  return true;
}  

int ChessBoard::checkInput(std::string start, std::string end){
  if ((start=="E1" || start=="E8") && (end=="0-0" || end=="0-0-0")){
    return 3;
  }
  
  if (start.length()!=2 || end.length()!=2){
    return 1;
  }
 
  if (!(aToH(start[0]) && oneToEight(start[1]) && aToH(end[0]) && oneToEight(end[1]))){
    return 1;
  }
 
  if (start==end){
    return 2;
  }

  return 0;
}


bool ChessBoard::castlingMove(std::string start, std::string end){
  int king_row;
  int king_column;
  makeIndices(start, king_row, king_column);
  int castle_row;
  int castle_column;
  setCastleSquare(end, castle_row, castle_column);
  //Kingside white
  if (start=="E1" && end=="0-0"){
    if (kingside_white && configuration[0][5]==nullptr && configuration[0][6]==nullptr && !inCheck()
            && !squareInCheck(0, 5) &&!squareInCheck(0, 6)){
        move(king_row, king_column, 0, 6);
        move(castle_row, castle_column, 0, 5);
        std::cout << "White castles kingside\n";
    }
    else
    return false;
  }
  //Queenside white
  if (start=="E1" && end=="0-0-0"){
    if (queenside_white && configuration[0][1]==nullptr && configuration[0][2]==nullptr && configuration[0][3]==nullptr && !inCheck()
            && !squareInCheck(0, 1) && !squareInCheck(0, 2) && !squareInCheck(0, 3)){
        move(king_row, king_column, 0, 2);
        move(castle_row, castle_column, 0, 3);
        std::cout << "White castles queenside\n";
    }
    else 
    return false;
  }
  //Kingside black
  if (start=="E8" && end=="0-0"){
    if (kingside_black && configuration[7][5]==nullptr && configuration[7][6]==nullptr && !inCheck()
            && !squareInCheck(7, 5) && !squareInCheck(7, 6)){
        move(king_row, king_column, 7, 6);
        move(castle_row, castle_column, 7, 5);
        std::cout << "Black castles kingside\n";
    }
    else
    return false;
  }
  //Queenside black
  if (start=="E8" && end=="0-0-0"){
    if (queenside_black && configuration[7][1]==nullptr && configuration[7][2]==nullptr && configuration[7][3]==nullptr && !inCheck()
            && !squareInCheck(7, 1) && !squareInCheck(7, 2) && !squareInCheck(7, 3)){
        move(king_row, king_column, 7, 2);
        move(7, 0, 7, 3);
        std::cout << "Black castles queenside\n";
    }
    else
    return false;
  }
  
  //switch colours
  if (current_colour=="White"){
    current_colour="Black";
  }
  else {
    current_colour="White";
  }

  //check for check/checkmate/stalemate
  if (inCheck()){
    if (checkmate()){
      std::cout << current_colour << " is in checkmate\n";
      game_over=true;
      return true;
    }
    std::cout << current_colour << " is in check\n";
    return true;
  }

  if (checkmate()){
    std::cout << current_colour << " cannot make a legal move. Game ends in stalemate.\n";
    game_over=true;
    return true;
  }
  
  return true;
}

void ChessBoard::noQueenside(){
  if (current_colour=="White" && queenside_white==true){
    queenside_white=false;
  }
  if (current_colour=="Black" && queenside_black==true){
    queenside_black=false;
  }
}
void ChessBoard::noKingside(){
  if (current_colour=="White" && kingside_white==true){
    kingside_white=false;
  }
  if (current_colour=="Black" && kingside_black==true){
    kingside_black=false;
  }
}


void ChessBoard::setCastleSquare(std::string str, int& castle_row, int& castle_column){
  if (str=="0-0" && current_colour=="White"){
    castle_row=0;
    castle_column=7;
    return;
  }
  if (str=="0-0" && current_colour=="Black"){
    castle_row=7;
    castle_column=7;
    return;
  }
  if (str=="0-0-0" && current_colour=="White"){
    castle_row=0;
    castle_column=0;
    return;
  }
  if (str=="0-0-0" && current_colour=="Black"){
    castle_row=7;
    castle_column=0;
    return;
  }
  return;
}

bool ChessBoard::squareInCheck(int row, int column){
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      if (configuration[i][j]!=nullptr){
        if (current_colour!=configuration[i][j]->getColour()){
          if (configuration[i][j]->validateMove(i, j, row, column)){
            return true;
          }
        }
      }
    }
  }
  return false;
}
