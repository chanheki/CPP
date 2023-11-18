#include "Span.hpp"

#include <cstdlib>
#include <ctime>

Span::Span(unsigned int N) : _limit(N), _size(0) {}

Span::~Span() {}

Span::Span(Span const &src)
    : _limit(src._limit), _size(src._size), _v(src._v) {}

Span &Span::operator=(Span const &src) {
  if (this != &src) {
    _limit = src._limit;
    _size = src._size;
    _v = std::vector<int>(src._v);
  }
  return *this;
}

void Span::addNumber(int n) {
  ++_size;
  if (_limit < _size) throw std::runtime_error("The span is full");
  _v.push_back(n);
}

unsigned int Span::shortestSpan() {
  if (_size < 2) throw std::runtime_error("shortestSpan Calculating Fail");
  sortVector();

  unsigned int shortestSpan = std::numeric_limits<unsigned int>::max();
  for (size_t i = 1; i < _v.size(); ++i) {
    unsigned int span = static_cast<unsigned int>(_v[i] - _v[i - 1]);
    if (span < shortestSpan) {
      shortestSpan = span;
    }
  }

  return shortestSpan;
}

unsigned int Span::longestSpan() {
  if (_size < 2) throw std::runtime_error("longestSpan Calculating Fail");
  sortVector();
  return _v.back() - _v.front();
}

void Span::printVector() { iter(_v, print); }

void Span::sortVector() { std::sort(_v.begin(), _v.end()); }

void Span::addRandomNumbers() {
  if (_size == _limit) throw std::runtime_error("Span is already full");
  _v.resize(_limit);
  std::srand((unsigned long)time(NULL));
  int sign = 1;

  for (std::vector<int>::iterator it = _v.begin() + _size;
       it != _v.begin() + _limit; ++it) {
    sign *= -1;
    *it = std::rand() * sign;
  }

  _size = _limit;
}
