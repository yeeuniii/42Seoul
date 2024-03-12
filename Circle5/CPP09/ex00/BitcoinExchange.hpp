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

		class InvalidDatabase : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class BadInput : public std::exception
		{
			protected:
				std::string	message;
			public:
				BadInput();
				BadInput(const std::string&);
				virtual ~BadInput() throw();
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
		class NotExistDate : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		
		static void		readDataBase(std::map<std::string, float>&);
		static char		findDelimiter(std::ifstream& database);
		static void		checkDatabaseFormat(const std::string& line, const char& delimiter);
		
		static void		processInput(const std::string&, std::map<std::string, float>&);
		static void		processOneLine(std::ifstream&, std::map<std::string, float>&);
		static float	multipleValueAndRate(const std::pair<std::string, float>&, std::map<std::string, float>&);
		
		static void		openInputFile(const std::string&, std::ifstream&);
		static std::pair<std::string, float> makeInputPair(const std::string&);
		static bool		isValidDate(const std::string&);
		static bool		isDateFormat(const std::string&);
		static void		checkValidValue(const std::string&);
		static void		checkValueFormat(const std::string&);
		
	public:
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange&);

		static void	run(const std::string& fileName);
};

bool	isFloatString(const std::string& string);
float	convertFloat(const std::string&);
int		convertInteger(const std::string&);

#endif