#include <conio.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

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
  int nomera[10], i, x = 1, j, flag, errors[10], vopr = 0, button;
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
  cout << "Ввод производится без запятых и с пробелом, с маленькой буквы."
       << endl;
  for (i = 0; i < 10; i++) {
    file.open(path);
    while (x <= nomera[i]) {
      words = "";
      getline(file, words);
      x++;
    }
    x = 1;
    j = 0;
    while (words[j] != ' ') {
      word += words[j];
      j++;
    }
    cout << "Введите вторую и третью формы глагола " << word << ":" << endl;
    cin >> answer;
    word += ' ';
    word += answer;
    cin >> answer;
    word += ' ';
    word += answer;
    if (word == words)
      errors[vopr] = 1;
    else
      errors[vopr] = 0;
    vopr++;
    word = "";
    file.close();
  }
  for (i = 0; i < 10; i++) {
    if (errors[i] == 1)
      cout << i + 1 << ". V" << endl;
    else {
      file.open(path);
      while (x <= nomera[i]) {
        words = "";
        getline(file, words);
        x++;
      }
      x = 1;
      cout << i + 1 << ". X   Правильный ответ: " << words << endl;
      file.close();
    }
  }
  cout << "Нажмите любую клавишу чтобы выйти";
  _getch();
}

void test2() {
  system("cls");
  system("cls");
  setlocale(LC_ALL, "ru");
  srand(time(NULL));

  string path = "..\\txtfile\\dictionary.txt";
  string words, word, answer;
  int nomera[10], i, x = 1, j, flag, errors[10], vopr = 0, poin, button;
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
  cout << "Ввод производится с маленькой буквы." << endl;
  for (i = 0; i < 10; i++) {
    file.open(path);
    while (x <= nomera[i]) {
      words = "";
      getline(file, words);
      x++;
    }
    x = 1;
    j = 0;
    while (words[j] != ' ') {
      j++;
    }
    poin = j;
    j++;
    while (j <= words.length()) {
      word += words[j];
      j++;
    }
    cout << "Введите инфинитив глагола, который имеет данные формы: " << word
         << endl;
    cin >> answer;
    words.erase(poin);
    if (answer == words)
      errors[vopr] = 1;
    else
      errors[vopr] = 0;
    vopr++;
    word = "";
    poin = 0;
    file.close();
  }
  cout << "Нажмите любую клавишу чтобы выйти";
  _getch();
}

void test3() { system("cls"); }

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
