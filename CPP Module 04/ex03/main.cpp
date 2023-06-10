#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Floor.hpp"

#ifdef LEAKS
void leaks(void)
{
	system("leaks Polymorphism");
}
#endif

int main()
{
	#ifdef LEAKS
	atexit(leaks);
	#endif
{
	Floor::start();

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	Floor::finish();
}
std::cout << "--------------------------------------" << std::endl;
{
	Floor::start();

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character *you = new Character("you");
	AMateria* materia;
	materia = src->createMateria("ice");
	you->equip(materia);
	materia = src->createMateria("cure");
	you->equip(materia);
	materia = src->createMateria("whatever");
	you->equip(materia);
	materia = src->createMateria("chanheki");
	you->equip(materia);
	materia = src->createMateria("cure");
	you->equip(materia);
	materia = src->createMateria("ice");
	you->equip(materia);
	
	ICharacter* chanheki = new Character("chanheki");
	you->use(0, *chanheki);
	you->use(1, *chanheki);
	you->use(2, *chanheki);
	you->use(3, *chanheki);
	you->use(4, *chanheki);
	you->use(-1, *chanheki);
	
	you->unequip(2);
	you->unequip(3);

	std::cout << "--------------------------------------" << std::endl;

	materia = src->createMateria("ice");
	chanheki->equip(materia);
	materia = src->createMateria("cure");
	chanheki->equip(materia);

	chanheki->use(0, *you);
	chanheki->use(1, *you);
	chanheki->use(2, *you);
	chanheki->use(3, *you);
	chanheki->use(4, *you);
	chanheki->use(-1, *you);

	chanheki->unequip(2);
	chanheki->unequip(3);

	delete you;
	delete chanheki;
	delete src;
	Floor::finish();
}
	return 0;
}