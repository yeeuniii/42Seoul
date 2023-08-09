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
	const AMateria	*slot;

	if (this == &character)
		return *this;
	this->name = character.name;
	deleteInventorySlot();
	for (int idx = 0; idx < character.size; idx++)
	{
		slot = character.inventory[idx];
		this->inventory[idx] = slot ? slot->clone() : 0;
	}
	this->size = character.size;
	return *this;
}

std::string const& Character::getName() const
{
	return this->name;
}

bool	Character::isValidIndex(int index) const
{
	return ((index >= 0 && index < acceptableSize) && this->inventory[index]);
}

void	Character::equip(AMateria* m)
{
	int	idx = 0;

	if (!m || this->size >= acceptableSize)
		return ;
	while (idx < 4 && this->inventory[idx])
		idx++;
	this->inventory[idx] = m;
	this->size++;
}

void	Character::unequip(int idx)
{
	if (isValidIndex(idx) == false)
		return ;
	this->inventory[idx] = 0;
	this->size--;
}

void	Character::use(int idx, ICharacter& target)
{
	if (isValidIndex(idx) == false)
		return ;
	this->inventory[idx]->use(target);
}

void	Character::deleteInventorySlot()
{
	for (int idx = 0; idx < acceptableSize; idx++)
	{
		if (this->inventory[idx])
			delete this->inventory[idx];
		this->inventory[idx] = 0;
	}
}

AMateria*	Character::getInventorySlot(int idx) const
{
	return isValidIndex(idx) ? this->inventory[idx] : 0;
}