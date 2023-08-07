#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->inventory = new AMateria*[this->acceptableSize];
	this->size = 0;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	this->inventory = new AMateria*[this->acceptableSize];
	*this = materiaSource;
}

MateriaSource::~MateriaSource()
{
	for (int idx = 0; idx < this->size; ++idx)
		delete this->inventory[idx];
	delete[] this->inventory;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& materiaSource)
{
	if (this == &materiaSource)
		return *this;
	this->size = materiaSource.size;
	for (int idx = 0; idx < materiaSource.size; ++idx)
	{
		this->inventory[idx] = materiaSource.inventory[idx]->clone();
	}
	return *this;
}

