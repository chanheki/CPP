#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) {
  if (this != &other) {
    _dataMap = other._dataMap;
  }
  return (*this);
}

BitcoinExchange::BitcoinExchange(int ac, char** av) {
  if (ac != 2) {
    printErrorExit("Error: could not open file");
  }

  openCsvFile();
  openInputFile(av[1]);
}

void BitcoinExchange::openCsvFile() {
  std::string csvPath = "./data.csv";
  std::ifstream csv(csvPath.c_str(), std::ifstream::in);
  if (!csv.is_open()) {
    printErrorExit("Error: Invalid File Open");
  }

  std::string line;
  std::getline(csv, line);
  if (line != "date,exchange_rate") {
    printErrorExit("Error: Unsupported formats data.csv => " + line);
  }

  while (std::getline(csv, line)) {
    size_t commaIndex = line.find(',');
    if (commaIndex == std::string::npos) {
      printErrorExit("CSV Error: bad input => " + line);
    }

    std::string leftSide = line.substr(0, commaIndex);
    std::string rightSide = line.substr(commaIndex + 1);

    eraseWhiteSpace(leftSide);
    eraseWhiteSpace(rightSide);

    std::istringstream iss(rightSide);
    double value;
    iss >> value;

    if (!checkValidDate(leftSide) || !checkCsvValidValue(rightSide)) {
      printErrorExit("CSV Error: bad input => " + line);
    }

    _dataMap[leftSide] = value;
  }
}

void BitcoinExchange::openInputFile(std::string av) {
  std::string _filename = av;
  std::ifstream _file(_filename.c_str(), std::ifstream::in);
  std::string line;

  if (!_file.is_open()) {
    printErrorExit("Error: Invalid File Open");
  }

  std::getline(_file, line);
  if (line != "date | value") {
    printErrorExit("Error: Unsupported formats input file");
  }

  while (std::getline(_file, line)) {
    this->parseLine(line);
  }
}

void BitcoinExchange::parseLine(std::string line) {
  if (checkValidInput(line)) {
    std::string date = line.substr(0, 10);
    std::string value = line.substr(13);

    if (date < _dataMap.begin()->first) {
      printError("Error: bad input => " + date);
      return;
    }

    std::map<std::string, double>::iterator it_upper =
        _dataMap.upper_bound(date);
    it_upper--;

    double doubleValue;
    std::istringstream(value) >> doubleValue;
    std::cout << date << " => " << value << " = "
              << it_upper->second * doubleValue << std::endl;
  }
}

int BitcoinExchange::checkValidInput(std::string line) {
  std::string before_pipe;
  std::string after_pipe;

  if (line.length() < 13 || line[10] != ' ' || line[11] != '|' ||
      line[12] != ' ') {
    printError("Error: bad input => " + line);
    return (0);
  }
  before_pipe = line.substr(0, 10);
  after_pipe = line.substr(13);
  if (checkValidDate(before_pipe) && checkInputValidValue(after_pipe))
    return (1);
  return (0);
}

int BitcoinExchange::checkValidDate(std::string line) {
  size_t i = 0;
  size_t len = line.length();

  if (len != 10) {
    printError("Error: bad input => " + line);
    return (0);
  }

  while (i < len) {
    if ((i < 4) || (i > 4 && i < 7) || (i > 7 && i < 10)) {
      if (!std::isdigit(line[i])) {
        printError("Error: bad input => " + line);
        return (0);
      }
    } else if (i == 4 || i == 7) {
      if (line[i] != '-') {
        printError("Error: bad input => " + line);
        return (0);
      }
    }
    i++;
  }

  std::string year = line.substr(0, 4);
  std::string month = line.substr(5, 2);
  std::string day = line.substr(8, 2);

  int YY = stringToInt(year);
  int MM = stringToInt(month);
  int DD = stringToInt(day);

  if (MM > 12 || MM < 1) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return (0);
  }

  if (MM == 2) {
    if (isLeapYear(YY) && (DD < 1 || DD > 29)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      return (0);
    } else if (!isLeapYear(YY) && (DD < 1 || DD > 28)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      return (0);
    }
  } else if (MM == 4 || MM == 6 || MM == 9 || MM == 11) {
    if (DD < 1 || DD > 30) {
      std::cerr << "Error: bad input => " << line << std::endl;
      return (0);
    }
  } else {
    if (DD < 1 || DD > 31) {
      std::cerr << "Error: bad input => " << line << std::endl;
      return (0);
    }
  }
  return (1);
}

int BitcoinExchange::checkCsvValidValue(std::string line) {
  std::istringstream iss(line);
  double value;
  iss >> value;

  if (!isNumberOrDot(line)) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return (0);
  }

  if (iss.fail()) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return (0);
  }

  if (value < 0) {
    std::cerr << "Error: not a positive number" << std::endl;
    return (0);
  }
  return (1);
}

int BitcoinExchange::checkInputValidValue(std::string line) {
  std::istringstream iss(line);
  double value;
  iss >> value;

  if (!isNumberOrDot(line)) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return (0);
  }

  if (iss.fail()) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return (0);
  }

  if (value <= 0) {
    std::cerr << "Error: not a positive number" << std::endl;
    return (0);
  } else if (value >= 1000) {
    std::cerr << "Error: too large a number" << std::endl;
    return (0);
  }
  return (1);
}

bool BitcoinExchange::isLeapYear(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int stringToInt(const std::string& str) { return std::atoi(str.c_str()); }

void printErrorExit(const std::string& str) {
  std::cerr << str << std::endl;
  std::exit(1);
}

void printError(const std::string& str) { std::cerr << str << std::endl; }

void eraseWhiteSpace(std::string& str) {
  std::string whitespaces(" \t\f\v\n\r");
  std::size_t found = str.find_last_not_of(whitespaces);
  if (found != std::string::npos)
    str.erase(found + 1);
  else
    str.clear();
}

bool isNumberOrDot(const std::string& line) {
  int dot = 0;
  for (size_t i = 0; i < line.length(); ++i) {
    if (line[i] == '.') {
      dot++;
      if (dot > 1) return false;
    }

    if (!std::isdigit(line[i]) && line[i] != '.') {
      return false;
    }
  }
  return true;
}
