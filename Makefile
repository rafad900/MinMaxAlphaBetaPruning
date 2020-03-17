.SUFFIXES: .o .cpp .x

CFLAGS=-ggdb

OBJECT_FILES=main.o TicTacToe.o

alphabeta.out: $(OBJECT_FILES)
	g++ $(CFLAGS) -o alphabeta.out $(OBJECT_FILES)

.cpp.o:
	g++ $(CFLAGS) -c $< -o $@

TicTacToe.o: TicTacToe.hpp TicTacToe.cpp
main.o: main.cpp TicTacToe.hpp TicTacToe.cpp

clean:
	rm -fr *.o *~ *.out
