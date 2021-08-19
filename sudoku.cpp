#include "board.h"

int main(int argc, char *argv[])
{
  Board board;
  board.set(0, 0, 2);
  board.set(0, 2, 1);
  board.set(0, 3, 5);
  board.set(0, 4, 8);
  board.set(0, 7, 3);
  board.set(1, 1, 3);
  board.set(1, 2, 4);
  board.set(1, 4, 9);
  board.set(1, 6, 8);
  board.set(1, 7, 5);
  board.set(2, 1, 6);
  board.set(2, 4, 7);
  board.set(3, 0, 8);
  board.set(3, 1, 2);
  board.set(3, 6, 1);
  board.set(4, 0, 1);
  board.set(4, 3, 8);
  board.set(4, 4, 4);
  board.set(4, 5, 6);
  board.set(4, 8, 2);
  board.set(5, 2, 3);
  board.set(5, 7, 8);
  board.set(5, 8, 5);
  board.set(6, 4, 2);
  board.set(6, 7, 1);
  board.set(7, 1, 1);
  board.set(7, 2, 2);
  board.set(7, 4, 5);
  board.set(7, 6, 9);
  board.set(7, 7, 6);
  board.set(8, 1, 8);
  board.set(8, 4, 6);
  board.set(8, 5, 3);
  board.set(8, 6, 2);
  board.set(8, 8, 7);
  board.print();
  board.findNumbers();
  board.print();
}
