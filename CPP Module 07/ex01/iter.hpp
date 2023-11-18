#pragma once

#include <iostream>

#define ARR_SIZE(x) (sizeof(x) / sizeof(x[0]))

template <typename T>
void iter(T *array, size_t arrayLength, void (*f)(T &)) {
  for (size_t i = 0; i < arrayLength; i++) {
    f(array[i]);
  }
}

template <typename T>
void print(T &t) {
  std::cout << t << std::endl;
}
