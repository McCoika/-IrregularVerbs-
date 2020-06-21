#define CATCH_CONFIG_MAIN
#include "../src/startmenu.hpp"
#include "../src/teor.hpp"
#include "../src/test.hpp"
#include "../thirdparty/catch.hpp"
#include <conio.h>
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
