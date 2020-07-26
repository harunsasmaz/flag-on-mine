CPP=g++
CCFLAGS=-std=c++14 -O3 -Wall
OBJ=minesweeper
SRC=main.cpp

compile:
	$(CPP) $(CCFLAGS) $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ)