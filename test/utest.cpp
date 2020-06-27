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

TEST_CASE("Verifying words ver.2", "[check]") {
  const int a = 1;
  const int b = 0;
  int errors[10], vopr = 0;
  string word = "ride rode ridden", words = "ride rode ridden";
  string word1 = "rid rode ridden", words1 = "ride rode ridden";
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

TEST_CASE("Verifying numbers test3 ver.2", "[checktest3]") {
  const char a = 'V';
  const char b = 'X';
  int num1 = 6, num2 = 3;
  char result1 = checktest3(num1, num2);
  char result2 = checktest3(num1, num1);
  REQUIRE(a == result2);
  REQUIRE(b == result1);
}
