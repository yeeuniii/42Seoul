#ifndef __C_HPP__
#define __C_HPP__

#include "Base.hpp"
#include <string>

class C : public Base
{
	private:
		std::string	type;

	public:
		C();
		virtual	~C();
		
		const std::string&	getType() const;
};

#endif