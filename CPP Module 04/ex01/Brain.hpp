#ifndef Brain_HPP
# define Brain_HPP

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain(void);
	Brain(const Brain& src);
	virtual ~Brain(void);
	Brain& operator=(Brain const& rhs);
};

#endif