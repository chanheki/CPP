#include <iostream>

int main(void) {
	std::string variable = "HI THIS IS BRAIN";
	std::string* stringPTR = &variable;
	std::string& stringREF = variable;

	std::cout << &variable << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << variable << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
