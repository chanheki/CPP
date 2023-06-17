#ifndef ScalarConvertor_HPP
#define ScalarConvertor_HPP

#include <cctype>
#include <cerrno>
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

typedef enum { CHAR, INT, FLOAT, DOUBLE, NONE } eTypes;

class ScalarConvertor {
 private:
  static int detectType(std::string const& str);
  static void* newChar(std::string const& str);
  static void* newInt(std::string const& str);
  static void* newFloat(std::string const& str);
  static void* newDouble(std::string const& str);

  static void convertChar(void* value, int type);
  static void convertInt(void* value, int type);
  static void convertFloat(void* value, int type);
  static void convertDouble(void* value, int type);

  ScalarConvertor(void);
  ScalarConvertor(const ScalarConvertor& src);
  virtual ~ScalarConvertor(void);
  ScalarConvertor& operator=(ScalarConvertor const& rhs);

 public:
  static void convert(std::string const& str);

  class NonConvertableException : public std::exception {
    const char* what(void) const throw();
  };

  class RangeErrorException : public std::exception {
    const char* what(void) const throw();
  };
};

#endif