#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <set>
#include <exception>

class Span
{
	private:
		std::set<int>	set;
		unsigned int	size;

		class NotUnableSave : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class NotFound : public std::exception
		{
			private:
				const char* message;
			public:
				NotFound(const char* message);
				virtual const char*	what() const throw();
		};
		
		Span();
		
		void	handleError() const;
		bool	canStored() const;
	
	public:
		Span(unsigned int N);
		Span(const Span& span);
		~Span();
		Span& operator=(const Span& span);

		void	addNumber(int number);
		void	addNumbers(int *numbers, unsigned int size);

		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

};

#endif