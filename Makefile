
run:
	g++ -o sudoku sudoku.cpp
	./sudoku

clean:
	rm -rf sudoku 2>/dev/null
