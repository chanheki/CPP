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
	std::string getNickName();
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setNickname(const  std::string& nickname);
	void setPhoneNumber(const std::string& phoneNumber);
	void setDarkestSecret(const std::string& darkestSecret);
	void displayContact();
};

#endif /* Contact_hpp */
