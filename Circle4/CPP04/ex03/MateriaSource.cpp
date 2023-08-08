#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	this->inventory = new AMateria*[acceptableSize];
	memset(this->inventory, 0, sizeof(AMateria*) * acceptableSize);
	this->size = 0;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	this->inventory = new AMateria*[acceptableSize];
	memset(this->inventory, 0, sizeof(AMateria*) * acceptableSize);
	*this = materiaSource;
}

MateriaSource::~MateriaSource()
{
	deleteInventorySlot();
	delete[] this->inventory;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& materiaSource)
{
	if (this == &materiaSource)
		return *this;
	deleteInventorySlot();
	for (int idx = 0; idx < materiaSource.size; idx++)
	{
		this->inventory[idx] = materiaSource.inventory[idx]->clone();
	}
	this->size = materiaSource.size;
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (this->size == 4)
	{
		delete materia;
		return ;
	}
	this->inventory[size] = materia;
	size++;
}
/* Copies the Materia passed as a parameter and store it in memory so it can be cloned
later. Like the Character, the MateriaSource can know at most 4 Materias. They
are not necessarily unique. */
// 4개가 넘으면?

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	int	idx = 0;

	while (idx < 4 && this->inventory[idx]->getType() != type)
		idx++;
	if (idx < 4)
		return this->inventory[idx]->clone();
	return 0;
}
/* Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if
the type is unknown. */
// 이게 뭔 소릴까 ... 후자가

void	MateriaSource::deleteInventorySlot()
{
	for (int idx = 0; idx < this->size; idx++)
		delete this->inventory[idx];
}