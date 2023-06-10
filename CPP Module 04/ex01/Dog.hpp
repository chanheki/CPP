#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog(void);
	Dog(const Dog &src);
	Dog(std::string type);
	Dog &operator=(const Dog &rhs);
	virtual ~Dog();
public:
	void makeSound(void) const;
};

#endif