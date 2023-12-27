#ifndef __A_HPP__
#define __A_HPP__

#include "Base.hpp"
#include <string>

class A : public Base
{
	private:
		std::string	type;

	public:
		A();
		virtual	~A();
		
		const std::string&	getType() const;
};

#endif