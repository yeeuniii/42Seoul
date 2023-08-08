#include "Character.hpp"

Character::Character()
{
	this->name = "anonymous";
	this->inventory = new AMateria*[acceptableSize];
	memset(this->inventory, 0, sizeof(AMateria*) * acceptableSize);
	this->size = 0;
}

Character::Character(const std::string &name)
{
	this->name = name;
	this->inventory = new AMateria*[acceptableSize];
	memset(this->inventory, 0, sizeof(AMateria*) * acceptableSize);
	this->size = 0;
}

Character::Character(const Character& character)
{
	this->inventory = new AMateria*[acceptableSize];
	memset(this->inventory, 0, sizeof(AMateria*) * acceptableSize);
	*this = character;
}

Character::~Character()
{
	deleteInventorySlot();
	delete[] this->inventory;
}

Character&	Character::operator=(const Character& character)
{
	if (this == &character)
		return *this;
	this->name = character.name;
	deleteInventorySlot();
	for (int idx = 0; idx < this->size; idx++)
	{
		this->inventory[idx] = character.inventory[idx]->clone();
	}
	this->size = character.size;
	return *this;
}

std::string const& Character::getName() const
{
	return this->name;
}

void	Character::equip(AMateria* m)
{
	if (this->size == acceptableSize)
		return ;
	this->inventory[this->size] = m;
	this->size++;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->size)
		return ;
	this->inventory[idx] = 0;
	this->size--;
	while (idx < acceptableSize - 1)
	{
		this->inventory[idx] = this->inventory[idx + 1];
		idx++;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->size)
		return ;
	this->inventory[idx]->use(target);
}

void	Character::deleteInventorySlot()
{
	for (int idx = 0; idx < this->size; idx++)
	{
		delete this->inventory[idx];
	}
}

AMateria*	Character::getInventorySlot(int idx) const
{
	if (idx < 0 || idx >= this->size)
		return 0;
	return this->inventory[idx];
}