FLAGS= -Wall -pedantic -std=c++17 -iquote inc

output: obj/main.o obj/klasa_sudoku.o
	g++ obj/main.o obj/klasa_sudoku.o  -o output
	

obj:
	mkdir obj
	
obj/main.o: src/main.cpp
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp	
	
obj/klasa_sudoku.o: src/klasa_sudoku.cpp inc/klasa_sudoku.h inc/wezel.h inc/rlutil.h
	g++ -c ${FLAGS} -o obj/klasa_sudoku.o src/klasa_sudoku.cpp

					
clean:
	rm obj/*.o output

