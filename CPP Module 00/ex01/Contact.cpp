//
//  Contact.cpp
//  cpp
//
//  Created by Chan on 2023/05/18.
//

#include "main.hpp"

void Contact::setFirstName(const std::string& firstName) { this->firstName = firstName; }
void Contact::setLastName(const std::string& lastName){ this->lastName = lastName; }
void Contact::setNickname(const std::string& nickname){ this->nickname = nickname; }
void Contact::setPhoneNumber(const std::string& phoneNumber){ this->phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(const std::string& darkestSecret){ this->darkestSecret = darkestSecret; }

std::string Contact::getFirstName() { return this->firstName;}
std::string Contact::getLastName() { return this->lastName; }
std::string Contact::getNickName() { return this->nickname; }

void Contact::displayContact() {
	std::cout << this->firstName << std::endl;
	std::cout << this->lastName << std::endl;
	std::cout << this->nickname << std::endl;
}
