#ifndef __B_HPP__
#define __B_HPP__

#include "Base.hpp"
#include <string>

class B : public Base
{
	private:
		std::string	type;

	public:
		B();
		virtual	~B();
		
		const std::string&	getType() const;
};

#endif