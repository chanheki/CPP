#ifndef WrongCat_HPP
# define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
public:
	WrongCat(void);
	WrongCat(std::string type);
	WrongCat(const WrongCat& src);
	virtual ~WrongCat(void);
	WrongCat& operator=(WrongCat const& rhs);
public:
	void makeSound(void) const;
};

#endif