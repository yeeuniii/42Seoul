#ifndef Weapon_HPP
#define Weapon_HPP

#include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon();
		Weapon(std::string type);
		
		std::string	getType() const;
		void		setType(std::string type);

};

#endif