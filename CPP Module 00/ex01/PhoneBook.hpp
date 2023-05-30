//
//  PhoneBook.hpp
//  cpp
//
//  Created by Chan on 2023/05/18.
//

#ifndef PhoneBook_hpp
#define PhoneBook_hpp

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
private:
	Contact	contacts[MAX_CONTACTS];
	int		oldestIndex;
	int		latestIndex;
	bool	isEmpty;

public:
	void addContact();
	void findContac();
	void printContacts();
	void contactInfo(int index);
	void info();
};

void addPhoneBook();

#endif /* PhoneBook_hpp */
