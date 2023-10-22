#ifndef __SOCKETERROR_HPP__
#define __SOCKETERROR_HPP__

#include <exception>

class SocketError : public std::exception {
	private:
		const char* message;
	public:
		SocketError(const char* message);	
	    virtual const char* what() const throw();
};

#endif