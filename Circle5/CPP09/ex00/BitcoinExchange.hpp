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
		BitcoinExchange(const BitcoinExchange&);
		
		static void	processInput(const std::string&, const std::map<std::string, float>&);
		static void	handleInputFile(const std::string&);
		static void	openInputFile(const std::string&, std::ifstream&);
		static void	readInputFile(std::ifstream&);
		static std::pair<std::string, float>	makeInputPair(const std::string&);
		static bool	isValidDate(const std::string&);
		static bool	checkDateFormat(const std::string&);
		static bool	checkValueFormat(const std::string&);
		
		static void		readDataBase(std::map<std::string, float>&);
		static float	convertFloat(std::string);
		static int		convertInteger(std::string string);

	public:
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange&);

		static void	run(const std::string& fileName);
};

#endif