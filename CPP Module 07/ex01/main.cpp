#include "iter.hpp"

int main(void) {
  int no[] = {1, 2, 3, 4, 5};
  std::string words[] = {"one", "two", "three", "four", "five"};
  double d[] = {1.1, 2.2, 3.3, 4.4, 5.5};

  iter(no, ARR_SIZE(no), print);
  iter(words, ARR_SIZE(words), print);
  iter(d, 5, print);

  return 0;
}