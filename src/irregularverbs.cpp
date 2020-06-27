#include "startmenu.hpp"
#include "teor.hpp"
#include "test.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
void startmenu();

int main() {
  bool close(false);
  setlocale(LC_ALL, "Russian");

  while (close == false) {
    system("cls");
    startmenu();
    char m = getchar();
    switch (m) {
    case '1':
      test1();
      break;
    case '2':
      test2();
      break;
    case '3':
      test3();
      break;
    case '4':
      teorinf();
      break;
    case '5':
      verbtable();
      break;
    case '6':
      close = true;
      break;
    default:
      break;
    }
  }
  return 0;
}
