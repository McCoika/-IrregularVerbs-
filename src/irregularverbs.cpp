#include <conio.h>
#include <iostream>
using namespace std;

void startmenu() {
  cout << "��� ������������ ��������� Irregularverbs\n\n";
  cout << "1 - ���� �1\n";
  cout << "2 - ���� �2\n";
  cout << "3 - ���� �3\n";
  cout << "4 - ������������� ����������\n";
  cout << "5 - ������� ������������ ��������\n";
  cout << "6 - �����\n";
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
