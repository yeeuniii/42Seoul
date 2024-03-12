#ifndef __BASE_HPP__
#define __BASE_HPP__

class Base
{
	public:
		virtual ~Base();
};

Base	*generate();
void	identify(Base *p);
void	identify(Base &p);

#endif