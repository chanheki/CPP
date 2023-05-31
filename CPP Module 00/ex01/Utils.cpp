//
//  UserInput.cpp
//  cpp
//
//  Created by Chan on 2023/05/18.
//

#include "main.hpp"

std::string resizeValue(std::string value) {
	if (value.length() > 10) {
		value.resize(9);
		value.resize(10, '.');
	}
	return value;
}

std::string getInputAddPhoneBook(const char *str) {
	std::string userInput;
	while (userInput.empty()) {
		std::cout << str;
		userInput = getUserInput();
	}
	return userInput;
}

static std::string stringToUppercase(std::string input){
	std::string returnValue;
	for (size_t i = 0; i < input.length(); i++)
		returnValue += std::toupper(input[i]);;
	return returnValue;
}

std::string getUserInputToUppercase() {
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::exit(0);
	} else {
		input = stringToUppercase(input);
	}
	return input;
}

std::string getUserInput() {
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof())
		std::exit(0);
	return input;
}
