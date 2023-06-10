#ifndef Floor_HPP
# define Floor_HPP

#include <iostream>
#include "AMateria.hpp"

class Floor
{
private:
	static AMateria *materias[100];
	static int idx;
	Floor();
	virtual ~Floor();
	Floor(Floor const &Floor);
	Floor &operator=(Floor const &Floor);
public:
	static void dropFloor(AMateria *materia);
	static void start();
	static void finish();
};

#endif