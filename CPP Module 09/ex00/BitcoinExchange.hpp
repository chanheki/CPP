#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
 private:
  BitcoinExchange(void);
  BitcoinExchange(BitcoinExchange const &other);
  BitcoinExchange &operator=(BitcoinExchange const &other);
  ~BitcoinExchange(void);

  std::map<std::string, double> _dataMap;

  void openCsvFile();
  void openInputFile(std::string av);
  void parseLine(std::string line);

  int checkValidInput(std::string line);
  int checkValidDate(std::string line);
  int checkInputValidValue(std::string line);
  int checkCsvValidValue(std::string line);
  bool isLeapYear(int year);

 public:
  BitcoinExchange(int ac, char **av);
};

int stringToInt(const std::string &str);
void eraseWhiteSpace(std::string &str);
void printErrorExit(const std::string &s);
void printError(const std::string &s);
bool isNumberOrDot(const std::string &line);

#endif
