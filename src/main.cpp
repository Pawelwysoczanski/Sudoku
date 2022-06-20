#include "../inc/klasa_sudoku.h"

using namespace std;

int main()
{
  srand(time(NULL));
  rlutil::cls();
  rlutil::setConsoleTitle("SUDOKU");
  cout << "Czesc! Zagrajmy w sudoku.\n"
       << endl;
  sudoku element;
  element.start();
  element.RuchTablicy();
  char m = rlutil::getkey();
  rlutil::cls();
  return m;
}
