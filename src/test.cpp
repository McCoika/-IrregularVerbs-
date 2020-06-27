#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void check(string word, string words, int errors[10], int vopr) {
  if (word == words)
    errors[vopr] = 1;
  else
    errors[vopr] = 0;
}

int randommas(int nomera[10], int i, int j) {
  if (nomera[i] == nomera[j])
    return 1;
  else
    return 0;
}

int randommascheck(int flag) {
  if (flag == 0)
    return 0;
  else
    return 1;
}

const char checktest3(int a, int b) {
  if (a == b)
    return ('V');
  else
    return ('X');
}

void test1() {
  system("cls");
  setlocale(LC_ALL, "ru");
  srand(time(NULL));

  cout << "В этом тесте вам нужно вписать первую и вторую форму неправильного "
          "глагола, который выведется на экран.\n"
          "Формат ответа: без запятых и с пробелом, с маленькой буквы.\n"
          "1 - Начать тест\n2- Вернуться в меню\n";

  bool close(false);
  while (close == false) {
    char m = getchar();
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
            flag += randommas(nomera, i, j);
          }
          t = randommascheck(flag);
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
        cout << "Введите вторую и третью формы глагола " << word << ":" << endl;
        cin >> answer;
        word += ' ';
        word += answer;
        cin >> answer;
        word += ' ';
        word += answer;
        check(word, words, errors, vopr);
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
      cout << "Введите любую клавишу чтобы выйти\n";
      char a;
      cin >> a;
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

  cout << "В этом тесте вам нужно вписать инфинитив для заданных первой и "
          "второй формы неправильного "
          "глагола.\n"
          "Формат ответа: с маленькой буквы.\n"
          "1 - Начать тест\n2- Вернуться в меню\n";

  bool close(false);
  while (close == false) {
    char m = getchar();
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
            flag += randommas(nomera, i, j);
          }
          t = randommascheck(flag);
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
        cout << "Введите инфинитив глагола, который имеет данные формы: "
             << word << endl;
        cin >> answer;
        words.erase(poin);
        check(answer, words, errors, vopr);
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
          cout << i + 1 << ". X   Правильный ответ: " << words << endl;
          file.close();
        }
      }
      cout << "Введите любую клавишу чтобы выйти\n";
      char a;
      cin >> a;
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
  cout << "В этом тесте вам нужно будет решить правильный или неправильный "
          "перед вами глагол\n"
          "Формат ответа: 1 - правильный глагол, 2 - неправильный глагол\n"
          "1 - Начать тест\n2 - Вернуться в меню\n";
  bool close(false);
  while (close == false) {
    char m = getchar();
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
          cout << endl << i + 1 << '.' << words << "\n Введите ответ:";
          cin >> mas[i][3];
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
          cout << endl << i + 1 << '.' << word << "\n Введите ответ:";
          cin >> mas[i][3];
        }
      }
      cout << endl;
      for (int i = 0; i < 10; i++)
        cout << i + 1 << '.' << checktest3(mas[i][1], mas[i][3]) << endl;
      cout << "\nВведите любую клавишу чтобы выйти\n";
      char a;
      cin >> a;
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
