//
//  PhoneBook.cpp
//  cpp
//
//  Created by Chan on 2023/05/18.
//

#include "main.hpp"
#include "Contact.hpp"

std::string getInputAddPhoneBook(const char *str) {
	std::string userInput;
	while (userInput.empty()) {
		std::cout << str;
		userInput = getUserInput();
	}
	return userInput;
}

void PhoneBook::addContact() {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	
	firstName = getInputAddPhoneBook("First Name: ");
	lastName = getInputAddPhoneBook("Last Name: ");
	nickname = getInputAddPhoneBook("Nickname: ");
	phoneNumber = getInputAddPhoneBook("Phone Number: ");
	darkestSecret = getInputAddPhoneBook("Darkest Secret: ");
	
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
	std::cout << "Add Complete!" << std::endl;
	
	contacts[this->oldestIndex].setNickname(firstName);
	contacts[this->oldestIndex].setLastName(lastName);
	contacts[this->oldestIndex].setNickname(nickname);
	contacts[this->oldestIndex].setPhoneNumber(phoneNumber);
	contacts[this->oldestIndex].setDarkestSecret(darkestSecret);
	
	this->oldestIndex = (this->oldestIndex + 1) % MAX_CONTACTS;
	std::cout << std::endl;
}

void PhoneBook::printContacts() {
	std::cout << std::setw(10) << "Index" << "|";
}
