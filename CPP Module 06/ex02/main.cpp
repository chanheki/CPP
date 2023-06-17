#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#ifdef LEAKS
void leaks(void) { system("leaks Identify"); }
#endif

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int test(void) {
  try {
    Base* random = generate();
    identify(random);
    identify(*random);
    delete random;
  } catch (std::bad_alloc& ba) {
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    return 1;
  }
  return 0;
}

int main(void) {
#ifdef LEAKS
  atexit(leaks);
#endif
  if (test()) return 1;
  std::cout << std::endl;
  // std::system("leaks Identify");
  return 0;
}
