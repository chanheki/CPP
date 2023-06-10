#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat(void);
	Cat(const Cat &src);
	Cat(std::string type);
	Cat &operator=(const Cat &rhs);
	virtual ~Cat();
public:
	void makeSound(void) const;
};

#endif
