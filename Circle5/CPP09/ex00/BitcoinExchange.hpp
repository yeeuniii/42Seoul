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
				BadInput(const std::string&);
				const char*	what() const throw();
		};
		class NotValidDate : public BadInput
		{
			public:
				NotValidDate(const std::string&);
		};
		class NotValidValue : public BadInput
		{
			public:
				NotValidValue(const std::string&);
		};

		BitcoinExchange();
		
		void	handleInputFile(const std::string& fileName);
		void	openInputFile(const std::string&, std::ifstream&);
		void	readInputFile(std::ifstream&);
		std::pair<std::string, float>	makeInputPair(const std::string&);
		bool	isValidDate(const std::string&);
		bool	isValidValue(const std::string&);
		
		void	readDataBase();
		float	convertFloat(std::string) const;

	public:
		BitcoinExchange(const std::string&);
		BitcoinExchange(const BitcoinExchange&);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange&);

		void	exchange();
};

#endif