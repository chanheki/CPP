#pragma once

#include <iostream>

#define ARR_SIZE(x) (sizeof(x) / sizeof(x[0]))

template <class T>
class Array {
 private:
  unsigned int _size;
  T *_array;

 public:
  Array(void) : _size(0), _array(NULL) {}
  Array(unsigned int n) : _size(n), _array(new T[n]) {}

  Array(const Array &src) : _size(src._size) {
    _array = new T[src._size];
    for (unsigned int i = 0; i < src._size; i++) _array[i] = src._array[i];
  }

  Array &operator=(const Array &rhs) {
    if (this == &rhs) return *this;
    this->~Array();
    new (this)Array(rhs);
    return *this;
  }

  ~Array(void) {
    if (this->_array) {
      delete[] this->_array;
    }
  }

  T &operator[](const unsigned int index) const {
    if (index >= this->_size) {
      throw ArrayOutOfBoundsException();
    }
    return this->_array[index];
  }
  
  const unsigned int& size(void) const { return (this->_size); }

 private:
  class ArrayOutOfBoundsException : public std::exception {
    virtual const char *what() const throw() { return ("Array out of bounds"); }
  };
};

template <typename T>
void iter(T *array, size_t arrayLength, void (*f)(T const &)) {
  for (size_t i = 0; i < arrayLength; i++) {
    f(array[i]);
  }
}

template <class T>
void print(T const &i) {
  std::cout << i << std::endl;
}