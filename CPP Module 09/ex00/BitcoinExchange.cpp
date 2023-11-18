#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(int ac, char** av) {
  if (ac != 2) {
    std::cerr << "Error: could not open file" << std::endl;
    std::exit(1);
  }

  csvToMap();
  openInputFile(av[1]);
}

void BitcoinExchange::csvToMap() {
  std::string csvPath = "./data.csv";
  std::ifstream csv(csvPath.c_str(), std::ifstream::in);
  if (!csv.is_open()) {
    std::cerr << "Error: Invalid File Open" << std::endl;
    std::exit(1);
  }

  std::string line;
  std::getline(csv, line);
  if (line != "date,exchange_rate") std::exit(1);
  while (std::getline(csv, line)) {
    line.erase(line.find_last_not_of(" \n\r\t") + 1);

    size_t commaIndex = line.find(',');
    if (commaIndex == std::string::npos) {
      std::cerr << "CSV Error: bad input => " << line << std::endl;
      std::exit(1);
    }

    std::string leftSide = line.substr(0, commaIndex);
    std::string rightSide = line.substr(commaIndex + 1);

    std::istringstream iss(rightSide);
    float value;
    iss >> value;

    if (!checkValidKey(leftSide) || !checkCsvValidValue(rightSide)) {
      std::cerr << "CSV Error: bad input => " << line << std::endl;
      std::exit(1);
    }

    _dataMap[leftSide] = value;
  }
}

void BitcoinExchange::openInputFile(std::string av) {
  _filename = av;
  std::ifstream _file(_filename.c_str(), std::ifstream::in);

  if (!_file.is_open()) {
    std::cerr << "Error: Invalid File Open" << std::endl;
    std::exit(1);
  }

  std::string line;
  while (std::getline(_file, line)) {
    this->parseLine(line);
  }
}

void BitcoinExchange::parseLine(std::string line) {
  if (line == "date | value") return;

  if (checkValidData(line)) {
    std::string year = line.substr(0, 4);
    std::string month = line.substr(5, 2);
    std::string day = line.substr(8, 2);
    std::string date = line.substr(0, 10);
    std::string value = line.substr(13);

    if (!parsingMapKey(year, month, day) || date < _dataMap.begin()->first) {
      std::cerr << "Error: bad input => " << date << std::endl;
      return;
    }
    std::map<std::string, float>::iterator it_upper =
        _dataMap.upper_bound(date);
    if (it_upper != _dataMap.begin() && it_upper->first != date) {
      it_upper--;
    }
    float floatValue;
    std::istringstream(value) >> floatValue;
    std::cerr << date << " => " << value << " = "
              << it_upper->second * floatValue << std::endl;
  }
}

int BitcoinExchange::checkValidData(std::string line) {
  std::string before_pipe;
  std::string after_pipe;

  if (line.length() < 13 || line[10] != ' ' || line[11] != '|' ||
      line[12] != ' ') {
    std::cerr << "Error: bad input => " << line << std::endl;
    return (0);
  }
  before_pipe = line.substr(0, 10);
  after_pipe = line.substr(13);
  if (checkValidKey(before_pipe) && checkValidValue(after_pipe)) return (1);
  return (0);
}

int BitcoinExchange::checkValidKey(std::string line) {
  size_t i = 0;
  size_t len = line.length();

  if (len != 10) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return (0);
  }

  while (i < len) {
    if ((i < 4) || (i > 4 && i < 7) || (i > 7 && i < 10)) {
      if (!isdigit(line[i])) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return (0);
      }
    } else if (i == 4 || i == 7) {
      if (line[i] != '-') {
        std::cerr << "Error: bad input => " << line << std::endl;
        return (0);
      }
    }
    i++;
  }

  std::string year = line.substr(0, 4);
  std::string month = line.substr(5, 2);
  std::string day = line.substr(8, 2);

  int iYear = stringToInt(year);
  int iMonth = stringToInt(month);
  int iDay = stringToInt(day);

  if (iMonth > 12 || iMonth < 1) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return (0);
  }

  if (iMonth == 2) {
    if (isLeapYear(iYear) && (iDay < 1 || iDay > 29)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      return (0);
    } else if (!isLeapYear(iYear) && (iDay < 1 || iDay > 28)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      return (0);
    }
  } else if (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11) {
    if (iDay < 1 || iDay > 30) {
      std::cerr << "Error: bad input => " << line << std::endl;
      return (0);
    }
  } else {
    if (iDay < 1 || iDay > 31) {
      std::cerr << "Error: bad input => " << line << std::endl;
      return (0);
    }
  }
  return (1);
}

int BitcoinExchange::checkValidValue(std::string line) {
  std::istringstream iss(line);
  double value;
  iss >> value;

  if (iss.fail()) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return (0);
  }

  if (value < 0) {
    std::cerr << "Error: not a positive number" << std::endl;
    return (0);
  } else if (value > 1000) {
    std::cerr << "Error: too large a number" << std::endl;
    return (0);
  }
  return (1);
}

int BitcoinExchange::checkCsvValidValue(std::string line) {
  std::istringstream iss(line);
  double value;
  iss >> value;

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

bool BitcoinExchange::parsingMapKey(std::string paraYear, std::string paraMonth,
                                    std::string paraDay) {
  int year;
  int month;
  int day;

  if (stringToInt(paraYear) < 0 || stringToInt(paraMonth) < 0 ||
      stringToInt(paraDay) < 0)
    return (0);

  year = stringToInt(paraYear);
  month = stringToInt(paraMonth);
  day = stringToInt(paraDay);

  if (year < 2009 || 2022 < year || month < 1 || 12 < month || day < 1 ||
      31 < day)
    return (0);
  if (day > 29 && month == 2) return (0);
  if (day == 29 && month == 2 && year % 4 != 0) return (0);
  if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    return (0);
  return (1);
}

bool BitcoinExchange::isLeapYear(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int BitcoinExchange::stringToInt(const std::string& str) {
  return std::atoi(str.c_str());
}
