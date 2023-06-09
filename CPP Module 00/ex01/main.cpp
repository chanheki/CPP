//
//  PhoneBook.cpp
//  cpp
//
//  Created by Chan on 2023/05/18.
//

#include "main.hpp"

void hostingLoop(PhoneBook phoneBook) {
	while (true) {
		std::cout << "You can only choose one of three options: Add, Search, or Exit." << std::endl;
		std::cout << "$> ";
		std::string userInput = getUserInputToUppercase();

		if (userInput == "\0" ) {
			continue ;
		} else if (userInput == "ADD") {
			phoneBook.addContact();
		} else if (userInput == "SEARCH") {
			phoneBook.searchContact();
			phoneBook.contactInfo();
		} else if (userInput == "EXIT") {
			break ;
		} else {
			std::cout << "Undefined behavior is ignored: " << userInput << std::endl;
		}
	}
}

int main() {
	PhoneBook phoneBook;
	std::cout << "Welcome PhoneBook" << std::endl;
	hostingLoop(phoneBook);
	return 0;
}
