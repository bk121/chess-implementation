objects = ChessMain.o ChessBoard.o Piece.o Pawn.o King.o Queen.o Bishop.o Knight.o Castle.o helper.o

chess : $(objects)
	g++ -g -Wall $(objects) -o chess

ChessMain.o : ChessMain.cpp ChessBoard.h Piece.h Pawn.h King.h Queen.h Bishop.h Knight.h Castle.h
	g++ -g -Wall -c ChessMain.cpp

Piece.o : Piece.cpp Piece.h ChessBoard.h
	g++ -g -Wall -c Piece.cpp

Pawn.o : Pawn.cpp Pawn.h
	g++ -g -Wall -c Pawn.cpp

King.o : King.cpp King.h
	g++ -g -Wall -c King.cpp

Queen.o :Queen.cpp Queen.h
	g++ -g -Wall -c Queen.cpp

Bishop.o :Bishop.cpp Bishop.h
	g++ -g -Wall -c Bishop.cpp

Knight.o :Knight.cpp Knight.h
	g++ -g -Wall -c Knight.cpp

Castle.o : Castle.cpp Castle.h
	g++ -g -Wall -c Castle.cpp

helper.o : helper.cpp helper.h
	g++ -g -Wall -c helper.cpp

clean:
	rm $(objects)
