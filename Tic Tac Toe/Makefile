# the compiler
CC = g++

# compiler flags
# -g    adds debugging information to the executable file
# -Wall turns on most, but not all, compiler warnings
CFLAGS = -g -Wall

#define any directories containing header files other than /usr/include
#
INCLUDES = -I /usr/include/SDL2/ 

#define any libraries to link into eecutable:
#
LIBS = -lSDL2 -lGL -lSDL2_image

# the build target executable:
#TARGET = TicTacToe

TicTacToe.out: main.o game.o graphics.o texture.o intro.o title.o play.o board.o button.o gameOver.o
	g++ -Wall -g $(INCLUDES) -o TicTacToe.out main.o game.o graphics.o texture.o intro.o title.o play.o board.o button.o gameOver.o $(LIBS)

main.o: main.cpp game.h gameState.h
	g++ -Wall -g $(INCLUDES) $(LIBS) -c main.cpp

game.o: game.cpp game.h
	g++ -Wall -g $(INCLUDES) $(LIBS) -c game.cpp

graphics.o: graphics.cpp graphics.h texture.h
	g++ -Wall -g $(INCLUDES) $(LIBS) -c graphics.cpp

texture.o: texture.cpp texture.h graphics.h
	g++ -Wall -g $(INCLUDES) $(LIBS) -c texture.cpp

intro.o: intro.cpp intro.h
	g++ -Wall -g $(INCLUDES) $(LIBS) -c intro.cpp

title.o: title.cpp title.h
	g++ -Wall -g $(INCLUDES) $(LIBS) -c title.cpp

play.o: play.cpp play.h
	g++ -Wall -g $(INCLUDES) $(LIBS) -c play.cpp

board.o: board.cpp board.h
	g++ -Wall -g $(INCLUDES) $(LIBS) -c board.cpp 

button.o: button.cpp button.h
	g++ -Wall -g $(INCLUDES) $(LIBS) -c button.cpp

gameOver.o: gameOver.cpp gameOver.h
	g++ -Wall -g $(INCLUDES) $(LIBS) -c gameOver.cpp

clean:
	rm -f main.o game.o graphics.o texture.o intro.o title.o play.o board.o button.o gameOver.o
