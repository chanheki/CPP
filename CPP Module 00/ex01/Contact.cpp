//
//  Contact.cpp
//  cpp
//
//  Created by Chan on 2023/05/18.
//

#include "main.hpp"

std::string Contact::getFirstName() { return this->firstName;}
std::string Contact::getLastName() { return this->lastName; }
std::string Contact::getNickname() { return this->nickname; }

bool Contact::getIndexInformation() {
	if (this->firstName.empty()) {
		return true;
	}
	return false;
}

void Contact::info() {
	std::cout << "- First name: " <<  this->firstName << std::endl;
	std::cout << "- Last name: " <<  this->lastName << std::endl;
	std::cout << "- Nickname: " <<  this->nickname << std::endl;
	std::cout << "- Phone number: " <<  this->phoneNumber << std::endl;
	std::cout << "- Darkest secret: " <<  this->darkestSecret << std::endl;
}

void Contact::setting() {
	this->firstName = getInputAddPhoneBook("First Name: ");
	this->lastName = getInputAddPhoneBook("Last Name: ");
	this->nickname = getInputAddPhoneBook("Nickname: ");
	this->phoneNumber = getInputAddPhoneBook("Phone Number: ");
	this->darkestSecret = getInputAddPhoneBook("Darkest Secret: ");
}

void Contact::showSetting() {
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
	std::cout << "Add Complete!" << std::endl;
}