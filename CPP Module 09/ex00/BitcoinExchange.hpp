#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
 private:
  BitcoinExchange(void);
  BitcoinExchange(BitcoinExchange const &other);
  BitcoinExchange &operator=(BitcoinExchange const &other);

  std::string _filename;
  std::map<std::string, float> _dataMap;

  void csvToMap();
  void openInputFile(std::string av);

  void parseLine(std::string line);
  bool parsingMapKey(std::string paraYear, std::string paraMonth,
                     std::string paraDay);
  int checkValidData(std::string line);
  int checkValidKey(std::string line);
  int checkValidValue(std::string line);
  int checkCsvValidValue(std::string line);
  bool isLeapYear(int year);

  int stringToInt(const std::string &str);

 public:
  ~BitcoinExchange(void);
  BitcoinExchange(int ac, char **av);
};

#endif
