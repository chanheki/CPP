#pragma once

#include <cstring>
#include <iostream>

template <typename T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T min(T a, T b) {
  return (a < b ? a : b);
}

template <typename T>
T max(T a, T b) {
  return (a > b ? a : b);
}

// Specialization template <>

template <>
const char *min<const char *>(const char *a, const char *b) {
  return (std::strcmp(a, b) < 0 ? a : b);
}

template <>
const char *max<const char *>(const char *a, const char *b) {
  return (std::strcmp(a, b) > 0 ? a : b);
}