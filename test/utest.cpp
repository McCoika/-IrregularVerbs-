#define CATCH_CONFIG_MAIN
#include "../src/startmenu.hpp"
#include "../src/teor.hpp"
#include "../src/test.hpp"
#include "../thirdparty/catch.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

TEST_CASE("Verifying words", "[check]") {
  const int a = 1;
  const int b = 0;
  int errors[10], vopr = 0;
  string word = "eat ate eaten", words = "eat ate eaten";
  string word1 = "ea ate eaten", words1 = "eat ate eaten";
  check(word, words, errors, vopr);
  vopr++;
  check(word1, words1, errors, vopr);
  REQUIRE(a == errors[0]);
  REQUIRE(b == errors[1]);
}

TEST_CASE("Verifying numbers test3", "[checktest3]") {
  const char a = 'V';
  const char b = 'X';
  int num1 = 1, num2 = 2;
  char result1 = checktest3(num1, num2);
  char result2 = checktest3(num1, num1);
  REQUIRE(a == result2);
  REQUIRE(b == result1);
}

TEST_CASE("Verifying mas elements", "[randommas]") {
  const int a = 1;
  const int b = 0;
  int nomera[10], i = 1, j = 2, flag = 0, flag1 = 0;
  nomera[1] = 20;
  nomera[2] = 20;
  flag += randommas(nomera, i, j);
  nomera[1] = 21;
  flag1 += randommas(nomera, i, j);
  REQUIRE(a == flag);
  REQUIRE(b == flag1);
}

TEST_CASE("Verifying flag", "[randommascheck]") {
  const int a = 1;
  const int b = 0;
  int flag = 0, t, t1;
  t = randommascheck(flag);
  flag++;
  t1 = randommascheck(flag);
  REQUIRE(b == t);
  REQUIRE(a == t1);
}
