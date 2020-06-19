#include <conio.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>

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

void test1() {
  system("cls");
  setlocale(LC_ALL, "ru");
  srand(time(NULL));

  string path = "..\\txtfile\\dictionary.txt";
  string words, word, answer;
  int nomera[10], i, x = 1, j, flag, errors[10], vopr = 0;
  bool t = true;

  ifstream file;
  nomera[0] = rand() % 109 + 1;
  for (i = 1; i < 10; i++) {
    t = true;
    while (t) {
      flag = 0;
      nomera[i] = rand() % 109 + 1;
      for (j = 0; j < i; j++) {
        if (nomera[i] == nomera[j])
          flag++;
      }

      if (flag == 0)
        t = false;
    }
  }
  file.open(path);
  if (file.is_open())
    cout << "1";
  else
    cout << "0";
}

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
