#include <conio.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

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
  cout << endl << endl << "������� ����� ������� ����� �����";
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
  cout << endl << endl << "������� ����� ������� ����� �����";
  _getch();
}
