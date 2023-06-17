
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "Serialization.hpp"

#define W 30

#ifdef LEAKS
void leaks(void) { system("leaks Serialization"); }
#endif

int test(void) {
  try {
    Data* ptr = new Data;
    uintptr_t s_ptr = Serialization::serialize(ptr);
    unsigned long ul_ptr = reinterpret_cast<unsigned long>(ptr);
    Data* ds_ptr = Serialization::deserialize(s_ptr);
    Data* origin_ptr = reinterpret_cast<Data*>(ul_ptr);

    std::cout << std::setw(W) << "ptr: ";
    std::cout << ptr << std::endl;

    std::cout << std::setw(W) << "serialized ptr: ";
    std::cout << s_ptr << std::endl;

    std::cout << std::setw(W) << "deserialized ptr: ";
    std::cout << ds_ptr << std::endl;

    std::cout << std::setw(W) << "ptr casted to unsigned long: ";
    std::cout << ul_ptr << std::endl;

    std::cout << std::setw(W) << "ptr casted back to Data*: ";
    std::cout << origin_ptr << std::endl;

    //		unsigned long test = static_cast<unsigned long>(ptr);
    delete ptr;
  } catch (const std::bad_alloc& ba) {
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
  // std::system("leaks Serialization");
  return 0;
}
