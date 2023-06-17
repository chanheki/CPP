#include "ScalarConvertor.hpp"

#ifdef LEAKS
void leaks(void) { system("leaks convert"); }
#endif

int main(int ac, char **av) {
  // the reason why we use static cast
  /*
  int* ptr = new int[10];
  char* cptr = static_cast<char*>(ptr);
  char* cptr = (char*)ptr;
  cptr[2147483647123] = 'A';
  */
#ifdef LEAKS
  atexit(leaks);
#endif
  if (ac != 2) {
    std::cout << "Usage: ./convert <string>" << std::endl;
    return (1);
  }
  try {
    ScalarConvertor::convert(av[1]);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  } catch (const std::bad_alloc &ba) {
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    return 1;
  } catch (...) {
    std::cout << "Unknown error" << std::endl;
  }

  return (0);
}