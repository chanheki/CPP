//
//  Contact.hpp
//  cpp
//
//  Created by Chan on 2023/05/18.
//

#ifndef Contact_hpp
#define Contact_hpp

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();

	bool getIndexInformation();
	void info();
	void setting();
	void showSetting();
};

#endif /* Contact_hpp */
