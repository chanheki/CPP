//
//  UserInput.cpp
//  cpp
//
//  Created by Chan on 2023/05/18.
//

#include "UserInput.hpp"

static std::string stringToUppercase(std::string input){
	std::string returnValue;
	for (size_t i = 0; i < input.length(); i++)
		returnValue += std::toupper(input[i]);;
	return returnValue;
}

std::string getUserInputToUppercase() {
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof() == true) {
		input = "eof";
	} else {
		input = stringToUppercase(input);
	}
	return input;
}

std::string getUserInput() {
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof() == true) {
		input.clear();
	}
	return input;
}
