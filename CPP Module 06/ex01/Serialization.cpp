#include "Serialization.hpp"

Serialization::Serialization(void) {}

Serialization::Serialization(const Serialization& src) { (void)src; }

Serialization::~Serialization(void) {}

Serialization& Serialization::operator=(Serialization const& rhs) {
  (void)rhs;
  return *this;
}

uintptr_t Serialization::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialization::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}
