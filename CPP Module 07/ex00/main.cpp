#include "whatever.hpp"

int main(void) {
  int a = 1;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

  std::string c = "chainea";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  std::cout << std::endl << "Test:" << std::endl;

  const char* s1 = "abcd";
  const char* s2 = "abc3";
  ::swap(s1, s2);
  std::cout << "c = " << s1 << ", d = " << s2 << std::endl;
  std::cout << "min( S1, S2 ) = " << ::min(s1, s2) << std::endl;
  std::cout << "max( S1, S2 ) = " << ::max(s1, s2) << std::endl;

  double e = 5.5;
  double f = 7.7;
  ::swap(e, f);
  std::cout << "e = " << e << ", f = " << f << std::endl;
  std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
  std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;
  return 0;
}