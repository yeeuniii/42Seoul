#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <map>
#include <string>
#include <fstream>

#define DB "data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, float>		data;
		std::multimap<std::string, float>	input;
		BitcoinExchange();
		
		float	convertfloat(std::string str) const;

		void	readInputFile(const std::string& fileName);
		void	readDataBase();

	public:
		BitcoinExchange(const std::string& fileName);
		BitcoinExchange(const BitcoinExchange& bitcoinExchange);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& bitcoinExchange);

		void	exchange();
};

#endif