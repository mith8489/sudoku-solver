
run:
	g++ -o sudoku -Wall sudoku.cpp
	./sudoku

clean:
	rm -rf sudoku 2>/dev/null
