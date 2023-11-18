#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Span {
 private:
  unsigned int _limit;
  unsigned int _size;
  std::vector<int> _v;

  Span();

 public:
  Span(unsigned int N);
  ~Span();
  Span(Span const &src);
  Span &operator=(Span const &src);

  void addNumber(int n);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  void printVector();
  void sortVector();
  void addRandomNumbers();
};

template <typename T>
void iter(const std::vector<T> &container, void (*f)(T const &)) {
  for (typename std::vector<T>::const_iterator it = container.begin();
       it != container.end(); ++it) {
    f(*it);
  }
}

template <typename T>
void print(T const &t) {
  std::cout << t << std::endl;
}
