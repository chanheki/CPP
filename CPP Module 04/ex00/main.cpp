#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#ifdef LEAKS
void leaks(void)
{
	system("leaks Polymorphism");
}
#endif

void test1()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *j2 = new WrongCat();
	std::cout << j2->getType() << " " << std::endl;
	j2->makeSound();
	meta2->makeSound();

	delete meta;
	delete j;
	delete i;
	delete meta2;
	delete j2;
}

void test2()
{
	Animal *a = new Dog("a dog");
	Animal *b = new Cat("b cat");

	a->makeSound();
	b->makeSound();
	std::cout << *a << std::endl;
	std::cout << *b << std::endl;
	delete a;
	delete b;
}

int main()
{
#ifdef LEAKS
	atexit(leaks);
#endif
	// test1();
	test2();

	return 0;
}
