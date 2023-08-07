#pragma once
#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "IMateriaSouce.hpp"

class MateriaSource : public IMateriaSource
{
	const static int	acceptableSize = 4;
	private:
		AMateria**	inventory;
		int			size;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &matriaSource);
		~MateriaSource();
		MateriaSource&	operator=(const MateriaSource &matriaSource);

		virtual void	learmMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const& type);

};

#endif