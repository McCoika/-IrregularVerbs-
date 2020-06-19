#include <conio.h>
#include <iostream>
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

void teorinf() { system("cls"); }

void verbtable() { system("cls"); }

void test1() { system("cls"); }

void test2() { system("cls"); }

void test3() { system("cls"); }

int main() {
  bool close(false);
  setlocale(LC_ALL, "Russian");
  startmenu();
  while (close == false) {
      
    if (_kbhit()) {
      switch (_getch()) {
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
      }
    }
  }
  return 0;
}
