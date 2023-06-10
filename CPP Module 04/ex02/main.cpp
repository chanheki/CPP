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

void test()
{
	// Animal *abstract = new Animal();
	Animal *Animals[] = {new Dog(), new Cat(), new Dog(), new Cat(), new Dog(), new Cat(), new Dog(), new Cat(), new Dog(), new Cat()};
	for (int i = 0; i < 10; i++)
	{
		Animals[i]->makeSound();
		delete Animals[i];
		Animals[i] = NULL;
	}

	Animal *j = new Dog();
	Animal *i = new Cat();
	Animal *dog = new Dog();
	
	*j = *dog;
	*i = *j;

	j->makeSound();
	i->makeSound();

	delete j; // should not create a leak
	delete i;
	delete dog;
}

int main()
{
#ifdef LEAKS
	atexit(leaks);
#endif
	test();
	return 0;
}