#include <conio.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

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

void verbtable() { system("cls"); }

void test1() {
  system("cls");
  setlocale(LC_ALL, "ru");
  srand(time(NULL));

  cout << "� ���� ����� ��� ����� ������� ������ � ������ ����� ������������� "
          "�������, ������� ��������� �� �����.\n"
          "������ ������: ��� ������� � � ��������, � ��������� �����.\n"
          "1 - ������ ����\n2- ��������� � ����";

  bool close(false);
  while (close == false) {
    char m = _getch();
    switch (m) {
    case '1': {
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
      cout << endl;
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
        cout << "������� ������ � ������ ����� ������� " << word << ":" << endl;
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
          cout << i + 1 << ". X   ���������� �����: " << words << endl;
          file.close();
        }
      }
      cout << "������� ����� ������� ����� �����";
      _getch();
    }
    case '2': {
      close = true;
      break;
    }
    default:
      break;
    }
  }
}

void test2() {
  system("cls");
  setlocale(LC_ALL, "ru");
  srand(time(NULL));

  cout << "� ���� ����� ��� ����� ������� ��������� ��� �������� ������ � "
          "������ ����� ������������� "
          "�������.\n"
          "������ ������: � ��������� �����.\n"
          "1 - ������ ����\n2- ��������� � ����";

  bool close(false);
  while (close == false) {
    char m = _getch();
    switch (m) {
    case '1': {
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
      cout << endl;
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
        cout << "������� ��������� �������, ������� ����� ������ �����: "
             << word << endl;
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
          cout << i + 1 << ". X   ���������� �����: " << words << endl;
          file.close();
        }
      }
      cout << "������� ����� ������� ����� �����";
      _getch();
    }
    case '2': {
      close = true;
      break;
    }
    default:
      break;
    }
  }
}

void test3() {
  system("cls");
  setlocale(LC_ALL, "ru");
  srand(time(NULL));
  cout << "� ���� ����� ��� ����� ����� ������ ���������� ��� ������������ "
          "����� ���� ������\n"
          "������ ������: 1 - ���������� ������, 2 - ������������ ������\n"
          "1 - ������ ����\n2 - ��������� � ����\n";
  bool close(false);
  while (close == false) {
    char m = _getch();
    switch (m) {
    case '1': {
      string n_irverbs = "..\\txtfile\\dictionary.txt",
             n_rverbs = "..\\txtfile\\regular_verbs.txt", words = "", word = "";
      ifstream file;
      int mas[10][3], x = 0;
      for (int i = 0; i < 10; i++) {
        mas[i][1] = rand() % 2 + 1;
        if (mas[i][1] == 1)
          mas[i][2] = rand() % 109 + 1;
        else
          mas[i][2] = rand() % 138 + 1;
      }
      for (int i = 0; i < 10; i++) {
        if (mas[i][1] == 1) {
          file.open(n_rverbs);
          x = 0;
          while (x <= mas[i][2]) {
            words = "";
            getline(file, words);
            x++;
          }
          file.close();
          cout << endl << i + 1 << '.' << words << "\n ������� �����():";
          bool close1(false);
          while (close1 == false) {
            char m1 = _getch();
            switch (m1) {
            case '1': {
              mas[i][3] = 1;
              close1 = true;
              break;
            }
            case '2': {
              mas[i][3] = 2;
              close1 = true;
              break;
            }
            default:
              break;
            }
          }
        } else {
          file.open(n_irverbs);
          x = 0;
          while (x <= mas[i][2]) {
            words = "";
            getline(file, words);
            x++;
          }
          file.close();
          x = 0;
          word = "";
          while (words[x] != ' ') {
            word += words[x];
            x++;
          }
          cout << endl << i + 1 << '.' << word << "\n ������� �����():";
          bool close1(false);
          while (close1 == false) {
            char m1 = _getch();
            switch (m1) {
            case '1': {
              mas[i][3] = 1;
              close1 = true;
              break;
            }
            case '2': {
              mas[i][3] = 2;
              close1 = true;
              break;
            }
            default:
              break;
            }
          }
        }
      }
      cout << endl;
      for (int i = 0; i < 10; i++) {
        if (mas[i][1] == mas[i][3])
          cout << i + 1 << ".V\n";
        else
          cout << i + 1 << ".X\n";
      }
      cout << "������� ����� ������� ����� �����";
      _getch();
    }
    case '2': {
      close = true;
      break;
    }
    default:
      break;
    }
  }
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
