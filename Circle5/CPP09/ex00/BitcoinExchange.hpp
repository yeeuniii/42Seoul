#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <map>
#include <string>
#include <fstream>
#include <exception>
#include <utility>

#define DB "data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, float>		data;
		std::multimap<std::string, float>	input;

		class BadInput : public std::exception
		{
			protected:
				const char*	message;
			public:
				BadInput();
				BadInput(const std::string&);
				const char*	what() const throw();
		};
		class InvalidDate : public BadInput
		{
			public:
				InvalidDate(const std::string&);
		};
		class InvalidDateFormat : public BadInput
		{
			public:
				InvalidDateFormat(const std::string&);
		};
		class NegativeValue : public BadInput
		{
			public:
				NegativeValue();
				const char*	what() const throw();
		};
		class TooLargeValue : public BadInput
		{
			public:
				TooLargeValue();
				const char*	what() const throw();
		};
		class InvalidValueFormat : public BadInput
		{
			public:
				InvalidValueFormat(const std::string&);
		};

		BitcoinExchange();
		
		void	handleInputFile(const std::string&);
		void	openInputFile(const std::string&, std::ifstream&) const;
		void	readInputFile(std::ifstream&);
		std::pair<std::string, float>	makeInputPair(const std::string&) const;
		bool	isValidDate(const std::string&) const;
		bool	checkDateFormat(const std::string&) const;
		void	checkValidValue(const std::string&) const;
		bool	checkValueFormat(const std::string&) const;
		
		void	readDataBase();
		float	convertFloat(std::string) const;
		int		convertInteger(std::string string) const;

	public:
		BitcoinExchange(const std::string&);
		BitcoinExchange(const BitcoinExchange&);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange&);

		void	exchange();
};

#endif