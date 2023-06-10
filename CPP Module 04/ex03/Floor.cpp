#include "Floor.hpp"

AMateria *Floor::materias[100];

int Floor::idx = 0;

Floor::Floor() {}

Floor::~Floor() {
	std::cout << "FLoor " << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (materias[i])
		{
			delete materias[i];
			materias[i] = NULL;
		}
	}
}

Floor::Floor(Floor const &Floor)
{
	*this = Floor;
}

Floor &Floor::operator=(Floor const &Floor)
{
	(void) Floor;
	return (*this);
}

void Floor::dropFloor(AMateria *materia)
{
	if (idx < 100)
	{
		materias[idx] = materia;
		idx++;
	} else {
		delete materias[idx%100];
		materias[idx%100] = materia;
	}
}

void Floor::start() {
	std::cout << "Floor start" << std::endl;
	std::memset(materias, 0, sizeof(materias));
}

void Floor::finish() {
	std::cout << "Floor finish" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (materias[i])
		{
			delete materias[i];
			materias[i] = NULL;
		}
	}
}