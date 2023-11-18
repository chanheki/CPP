#include <limits>

#include "Span.hpp"

int main(void) {
  Span sp = Span(5);

  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  print(sp.shortestSpan());
  print(sp.longestSpan());

  print("P-");
  sp.printVector();

  print("--");

  Span b = Span(7);
  b.addNumber(-1);
  try {
    print(b.shortestSpan());
  } catch (std::runtime_error e) {
    print(e.what());
  }

  try {
    print(b.longestSpan());
  } catch (std::runtime_error e) {
    print(e.what());
  }

  print("--");

  Span my = Span(10000);

  my.addRandomNumbers();

  print(my.shortestSpan());
  print(my.longestSpan());

  return 0;
}