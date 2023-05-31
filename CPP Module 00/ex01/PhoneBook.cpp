//
//  PhoneBook.cpp
//  cpp
//
//  Created by Chan on 2023/05/18.
//

#include "main.hpp"

PhoneBook::PhoneBook() {
	this->oldestIndex = 0;
}

void PhoneBook::addContact() {
	contacts[this->oldestIndex].setting();
	contacts[this->oldestIndex].showSetting();
	this->oldestIndex = (this->oldestIndex + 1) % MAX_CONTACTS;
	std::cout << std::endl;
}

void PhoneBook::searchContact() {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		Contact contact = this->contacts[i];
		if (contact.getIndexInformation()) {break;}
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << resizeValue(contact.getFirstName()) << "|";
		std::cout << std::setw(10) << resizeValue(contact.getLastName()) << "|";
		std::cout << std::setw(10) << resizeValue(contact.getNickname()) << "|" << std::endl;
	}
}

void PhoneBook::contactInfo() {
	std::cout << "Enter the index to look for\n$> ";
	int index = atoi(getUserInput().c_str());
	if (index > 0 && index < 9) {
		if(!this->contacts[index - 1].getIndexInformation())
			this->contacts[index - 1].info();
		else 
			std::cout << "No value in that index" << std::endl;
	} else {
		std::cout << "Invalid value" << std::endl;
	}
}