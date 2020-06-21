#include <conio.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "test.hpp"

using namespace std;

void startmenu() {
  cout << "Вас приветствует программа Irregularverbs\n\n";
  cout << "1 - Тест №1\n";
  cout << "2 - Тест №2\n";
  cout << "3 - Тест №3\n";
  cout << "4 - Теоритическая информация\n";
  cout << "5 - Таблица неправильных глаголов\n";
  cout << "6 - Выход\n";
}

void teorinf() {
  system("cls");
  setlocale(LC_ALL, "ru");
  string path = "..\\txtfile\\theory.txt";
  ifstream file;
  char sim;
  file.open(path);
  while (file.get(sim)) {
    cout << sim;
  }
  cout << endl << endl << "Нажмите любую клавишу чтобы выйти";
  _getch();
}

void verbtable() {
  system("cls");
  setlocale(LC_ALL, "ru");
  string slova, path = "..\\txtfile\\dictionary.txt";
  ifstream file;
  file.open(path);
  while (!file.eof()) {
    slova = "";
    getline(file, slova);
    cout << slova << endl << "--------------------------------" << endl;
  }
  cout << endl << endl << "Нажмите любую клавишу чтобы выйти";
  _getch();
}



int main() {
  bool close(false);
  setlocale(LC_ALL, "Russian");

  while (close == false) {
    system("cls");
    startmenu();
    char m = _getch();
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
