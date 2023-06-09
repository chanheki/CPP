#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
  int val;

  std::srand(time(NULL));
  val = std::rand() % 3;
  switch (val) {
    case 0:
      return new A;
    case 1:
      return new B;
    case 2:
      return new C;
  }
  return NULL;
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p) != NULL)
    std::cout << "it is an instance of class A" << std::endl;
  else if (dynamic_cast<B*>(p) != NULL)
    std::cout << "it is an instance of class B" << std::endl;
  else if (dynamic_cast<C*>(p) != NULL)
    std::cout << "it is an instance of class C" << std::endl;
  else
    std::cout << "it is not an instance of any class" << std::endl;
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "it is an instance of class A" << std::endl;
  } catch (std::bad_cast& bc) {
  }
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "it is an instance of class B" << std::endl;
  } catch (std::bad_cast& bc) {
  }
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "it is an instance of class C" << std::endl;
  } catch (std::bad_cast& bc) {
  }
}
