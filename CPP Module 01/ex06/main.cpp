#include "Harl.hpp"

int	main(int argc, char **argv) {
	if(argc != 2) {
		std::cout << "Invalid usage. Please provide log level.\n";
		return 1;
	}
	Harl harl(argv[1]);
	harl.harlFilter();
	return 0;
}
