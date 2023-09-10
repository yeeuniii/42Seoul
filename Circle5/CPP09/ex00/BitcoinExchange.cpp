#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <utility>

BitcoinExchange::BitcoinExchange() {}
		
BitcoinExchange::BitcoinExchange(const std::string& fileName)
{
	readInputFile(fileName);
	readDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bitcoinExchange)
{
	*this = bitcoinExchange;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& bitcoinExchange)
{
	if (this != &bitcoinExchange)
	{
		this->data = bitcoinExchange.data;
		this->input = bitcoinExchange.input;
	}
	return *this;
}

void	BitcoinExchange::readDataBase()
{
	std::ifstream	database;
	std::string		date;
	std::string		rate;

	database.open(DB);
	if (database.is_open() == false)
		throw std::ifstream::failure("Error: could not open file.");
	std::getline(database, date);
	while (database.eof() == false)
	{
		std::getline(database, date, ',');
		std::getline(database, rate, '\n');
		this->data.insert(std::make_pair(date, convertfloat(rate)));
	}
	// std::map<std::string, float>::iterator itr = this->data.begin();
	// for(; itr != this->data.end(); itr++)
	// 	std::cout << itr->first << "," << itr->second << std::endl;
}

float	BitcoinExchange::convertfloat(std::string str) const
{
	float	_float;
	
	std::stringstream ss;
	
	ss << str;
	ss >> _float;
	return _float;
}

void	BitcoinExchange::readInputFile(const std::string& fileName)
{
	(void)fileName;
}