#include "Array.hpp"

int main(void) {
  int* a = new int();
  print(a);

  print("Construction with an unsigned int n as a parameter");
  Array<int> b(4);
  b[0] = 21;
  b[1] = 42;
  b[2] = 84;
  b[3] = 168;
  iter(&b[0], 4, print);

  print("\nCopy");
  Array<int> c(b);
  b[0] = 5;
  iter(&c[0], c.size(), print);

  print("\nAssignment");
  Array<int> d;
  d = b;
  b[0] = 7;
  iter(&d[0], ARR_SIZE(d), print);

  print("\nArray indexing");
  try {
    b[4] = 0;
    b[-1] = 0;
  } catch (const std::exception& e) {
    print(e.what());
  }
  return 0;
}