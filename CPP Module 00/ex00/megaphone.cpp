//
//  main.cpp
//  cpp
//
//  Created by Chan on 2023/05/12.
//

#include <iostream>

void printUppercase(int argc, char **argv){
	for (int i = 1; i < argc; i++) {
		std::string word = argv[i];
		for (size_t j = 0; j < word.length(); j++) {
			char c = std::toupper(word[j]);
			std::cout << c;
		}
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
		printUppercase(argc, argv);
	return 0;
}
