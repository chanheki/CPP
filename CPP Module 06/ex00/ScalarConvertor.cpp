#include "ScalarConvertor.hpp"

ScalarConvertor::ScalarConvertor() {}
ScalarConvertor::~ScalarConvertor() {}
ScalarConvertor::ScalarConvertor(const ScalarConvertor& src) { (void)src; }
ScalarConvertor& ScalarConvertor::operator=(const ScalarConvertor& src) {
  (void)src;
  return *this;
}

int ScalarConvertor::detectType(std::string const& str) {
  int type = NONE;
  size_t len = str.length();

  if (len == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
    type = CHAR;
  } else if (str == "-inff" || str == "+inff" || str == "nanf" ||
             str == "inff") {
    type = FLOAT;
  } else if (str == "-inf" || str == "+inf" || str == "nan" || str == "inf") {
    type = DOUBLE;
  } else {
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+') {
      i++;
    }
    while (i < len && !std::isdigit(str[i])) {
      i++;
    }
    if (i == len) {
      type = INT;
    } else if (str[i] == '.') {
      i++;
      while (i < len && !std::isdigit(str[i])) {
        i++;
      }
      if (i == len) {
        type = FLOAT;
      } else if (str[i] == 'f' && i + 1 == len) {
        type = FLOAT;
      } else if (str[i] == 'f' && i + 1 < len) {
        type = NONE;
      } else if (str[i] != 'f') {
        type = DOUBLE;
      }
    }
  }
  return type;
}

void* ScalarConvertor::newChar(std::string const& str) {
  char* c = new char;
  *c = str[0];
  return static_cast<void*>(c);
}

void* ScalarConvertor::newInt(std::string const& str) {
  int* i = new int;
  long temp = std::strtol(str.c_str(), NULL, 10);
  if (errno == ERANGE || temp != (int)temp) {
    delete i;
    throw ScalarConvertor::RangeErrorException();
  }
  return static_cast<void*>(i);
}

void* ScalarConvertor::newFloat(std::string const& str) {
  float* f = new float;
  *f = static_cast<float>(std::strtod(str.c_str(), NULL));
  if (errno == ERANGE) {
    delete f;
    throw ScalarConvertor::RangeErrorException();
  }
  return static_cast<void*>(f);
}

void* ScalarConvertor::newDouble(std::string const& str) {
  double* d = new double;
  *d = std::strtod(str.c_str(), NULL);
  if (errno == ERANGE) {
    delete d;
    throw ScalarConvertor::RangeErrorException();
  }
  return static_cast<void*>(d);
}

void ScalarConvertor::convertChar(void* value, int type) {
  char printVal;
  int itemp;
  float ftemp;
  double dtemp;
  bool eflag;

  printVal = 0;
  eflag = false;
  std::cout << "char: ";
  switch (type) {
    case CHAR:
      printVal = *(static_cast<char*>(value));
      break;
    case INT:
      itemp = *(static_cast<int*>(value));
      if (itemp < 0 || itemp > 127) {
        std::cout << "impossible" << std::endl;
        eflag = true;
        break;
      } else if (std::isprint(itemp) == false) {
        std::cout << "Non displayable" << std::endl;
        eflag = true;
        break;
      }
      printVal = static_cast<char>(itemp);
      break;
    case FLOAT:
      ftemp = *(static_cast<float*>(value));
      if (ftemp < 0 || ftemp > 127 || ftemp - static_cast<int>(ftemp) != 0.0f) {
        std::cout << "impossible" << std::endl;
        eflag = true;
        break;
      }
      if (std::isprint(static_cast<int>(ftemp)) == false) {
        std::cout << "Non displayable" << std::endl;
        eflag = true;
        break;
      }
      printVal = static_cast<char>(ftemp);
      break;
    case DOUBLE:
      dtemp = *(static_cast<double*>(value));
      if (dtemp < 0 || dtemp > 127 || dtemp - static_cast<long>(dtemp) != 0.0) {
        std::cout << "impossible" << std::endl;
        eflag = true;
        break;
      }
      if (std::isprint(static_cast<int>(dtemp)) == false) {
        std::cout << "Non displayable" << std::endl;
        eflag = true;
        break;
      }
      printVal = static_cast<char>(dtemp);
  }
  if (eflag == false) std::cout << printVal << std::endl;
}

void ScalarConvertor::convertInt(void* value, int type) {
  int printVal;
  char ctemp;
  float ftemp;
  double dtemp;
  bool eflag;

  eflag = false;
  std::cout << "int: ";
  switch (type) {
    case CHAR:
      ctemp = *(static_cast<char*>(value));
      printVal = static_cast<int>(ctemp);
      break;
    case INT:
      printVal = *(static_cast<int*>(value));
      break;
    case FLOAT:
      ftemp = *(static_cast<float*>(value));
      if (ftemp > std::numeric_limits<int>::max() ||
          ftemp < std::numeric_limits<int>::lowest() || std::isnan(ftemp)) {
        std::cout << "impossible" << std::endl;
        eflag = true;
        break;
      }
      printVal = static_cast<int>(ftemp);
      break;
    case DOUBLE:
      dtemp = *(static_cast<double*>(value));
      if (dtemp > std::numeric_limits<int>::max() ||
          dtemp < std::numeric_limits<int>::lowest() || std::isnan(dtemp)) {
        std::cout << "impossible" << std::endl;
        eflag = true;
        break;
      }
      printVal = static_cast<int>(dtemp);
  }
  if (eflag == false) std::cout << printVal << std::endl;
}

void ScalarConvertor::convertFloat(void* value, int type) {
  float printVal;
  char ctemp;
  int itemp;
  double dtemp;
  bool eflag;

  eflag = false;
  std::cout << "float: ";
  switch (type) {
    case CHAR:
      ctemp = *(static_cast<char*>(value));
      printVal = static_cast<float>(ctemp);
      break;
    case INT:
      itemp = *(static_cast<int*>(value));
      printVal = static_cast<float>(itemp);
      break;
    case FLOAT:
      printVal = *(static_cast<float*>(value));
      break;
    case DOUBLE:
      dtemp = *(static_cast<double*>(value));
      if (dtemp > std::numeric_limits<float>::max() ||
          dtemp < std::numeric_limits<float>::lowest()) {
        std::cout << "impossible" << std::endl;
        eflag = true;
      }
      printVal = static_cast<float>(dtemp);
  }
  if (eflag == false) {
    std::cout << printVal;
    if (printVal < 1e6f && printVal > -1e6f &&
        printVal == static_cast<int>(printVal))
      std::cout << ".0";
    std::cout << 'f' << std::endl;
  }
}

void ScalarConvertor::convertDouble(void* value, int type) {
  double printVal;
  char ctemp;
  int itemp;
  float ftemp;

  std::cout << "double: ";
  switch (type) {
    case CHAR:
      ctemp = *(static_cast<char*>(value));
      printVal = static_cast<double>(ctemp);
      break;
    case INT:
      itemp = *(static_cast<int*>(value));
      printVal = static_cast<double>(itemp);
      break;
    case FLOAT:
      ftemp = *(static_cast<float*>(value));
      printVal = static_cast<double>(ftemp);
      break;
    case DOUBLE:
      printVal = *(static_cast<double*>(value));
  }
  std::cout << printVal;
  if (printVal < 1e6 && printVal > -1e6 &&
      printVal == static_cast<int>(printVal))
    std::cout << ".0";
  std::cout << std::endl;
}

void ScalarConvertor::convert(const std::string& str) {
  int type;
  void* value;

  type = detectType(str);
  switch (type) {
    case CHAR:
      value = ScalarConvertor::newChar(str);
      break;
    case INT:
      value = ScalarConvertor::newInt(str);
      break;
    case FLOAT:
      value = ScalarConvertor::newFloat(str);
      break;
    case DOUBLE:
      value = ScalarConvertor::newDouble(str);
      break;
    default:
      throw ScalarConvertor::NonConvertableException();
  }
  ScalarConvertor::convertChar(value, type);
  ScalarConvertor::convertInt(value, type);
  ScalarConvertor::convertFloat(value, type);
  ScalarConvertor::convertDouble(value, type);

  char* ctemp;
  int* itemp;
  float* ftemp;
  double* dtemp;

  switch (type) {
    case CHAR:
      ctemp = static_cast<char*>(value);
      delete ctemp;
      break;
    case INT:
      itemp = static_cast<int*>(value);
      delete itemp;
      break;
    case FLOAT:
      ftemp = static_cast<float*>(value);
      delete ftemp;
      break;
    case DOUBLE:
      dtemp = static_cast<double*>(value);
      delete dtemp;
  }
}

const char* ScalarConvertor::NonConvertableException::what(void) const throw() {
  return ("error: non-convertable literal as input");
}

const char* ScalarConvertor::RangeErrorException::what(void) const throw() {
  return ("error: out of range");
}