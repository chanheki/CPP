#ifndef Serialization_HPP
#define Serialization_HPP

#include <cstdint>

typedef struct sData {
  int data;
} Data;

class Serialization {
 private:
  Serialization(void);
  Serialization(const Serialization& src);
  virtual ~Serialization(void);
  Serialization& operator=(Serialization const& rhs);

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif