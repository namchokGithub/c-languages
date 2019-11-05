puzzle: puzzle.c puzzlelib.o puzzle.h
	gcc -o puzzle puzzle.c puzzlelib.o
puzzlelib.o: puzzlelib.c puzzle.h
	gcc -c puzzlelib.c
clean:
	rm -rf *.o puzzle
