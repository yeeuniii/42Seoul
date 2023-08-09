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
	const AMateria	*slot;

	if (this == &materiaSource)
		return *this;
	deleteInventorySlot();
	for (int idx = 0; idx < acceptableSize; idx++)
	{
		slot = materiaSource.inventory[idx];
		this->inventory[idx] = slot ? slot->clone() : 0;
	}
	this->size = materiaSource.size;
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	int	idx = 0;

	if (this->size >= 4)
	{
		delete materia;
		return ;
	}
	while (idx < 4 && this->inventory[idx])
		idx++;
	this->inventory[idx] = materia;
	size++;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	const AMateria	*slot;
	int		idx = -1;
	bool	exist = false;

	while (exist == false && ++idx < acceptableSize)
	{	
		slot = this->inventory[idx];
		exist = slot ? slot->getType() == type : false;
	}
	return exist ? this->inventory[idx]->clone() : 0;
}

void	MateriaSource::deleteInventorySlot()
{
	for (int idx = 0; idx < this->size; idx++)
	{
		if (this->inventory[idx])
			delete this->inventory[idx];
		this->inventory[idx] = 0;
	}
}