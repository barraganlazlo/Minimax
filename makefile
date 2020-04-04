all : minimax

minimax :
	g++ -Wall -I ./headers -o ./bin/minimax   sources/parser.cpp  sources/game.cpp sources/minimax.cpp sources/main.cpp
