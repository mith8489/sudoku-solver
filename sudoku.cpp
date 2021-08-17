#include "board.h"

int main(int argc, char *argv[])
{
  Board board;
  //  board.print();
  board.set(0, 5, 5);
  board.set(0, 2, 2);
  board.set(0, 7, 7);
  board.set(0, 6, 1);
  board.set(1, 2, 8);
  board.set(2, 0, 9);
  board.set(2, 2, 3);
  board.set(1, 0, 4);
  board.findNumber(0,0);
}
