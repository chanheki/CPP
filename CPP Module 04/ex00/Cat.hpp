#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &src);
	Cat(std::string type);
	Cat &operator=(const Cat &rhs);
	~Cat();
public:
	void makeSound(void) const;
};

#endif
