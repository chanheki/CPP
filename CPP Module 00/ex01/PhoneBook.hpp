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

public:
	PhoneBook();
	void addContact();
	void searchContact();
	void contactInfo();
};

#endif /* PhoneBook_hpp */
