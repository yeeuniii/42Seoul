#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <cstring>

BitcoinExchange::BadInput::BadInput(const std::string& detail)
{
	std::string	message;

	message = "Error: bad input => " + detail;
	this->message = message.c_str();
}

const char* BitcoinExchange::BadInput::what() const throw()
{
	return this->message;
}

BitcoinExchange::NotValidDate::NotValidDate(const std::string& detail) : BadInput(detail)
{
	std::string	message;

	message = "Error: non-existent date. => " + detail;
	this->message = message.c_str();
}

BitcoinExchange::NotValidValue::NotValidValue(const std::string& detail) : BadInput(detail)
{
	std::string	message;

	message = "Error: " + detail;
	this->message = message.c_str();
}

BitcoinExchange::BitcoinExchange() {}
		
BitcoinExchange::BitcoinExchange(const std::string& fileName)
{
	try
	{
		handleInputFile(fileName);
		readDataBase();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "error" << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bitcoinExchange)
{
	*this = bitcoinExchange;
}

BitcoinExchange::~BitcoinExchange() {std::cout << "destruct" << std::endl;}

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
		this->data.insert(std::make_pair(date, convertFloat(rate)));
	}
	database.close();
	// std::map<std::string, float>::iterator itr = this->data.begin();
	// for(; itr != this->data.end(); itr++)
	// 	std::cout << itr->first << "," << itr->second << std::endl;
}

float	BitcoinExchange::convertFloat(std::string str) const
{
	float	_float;
	
	std::stringstream ss;
	
	ss << str;
	ss >> _float;
	return _float;
}

void	BitcoinExchange::handleInputFile(const std::string& fileName)
{
	std::ifstream	inputFile;

	openInputFile(fileName, inputFile);
	readInputFile(inputFile);
	inputFile.close();
}

void	BitcoinExchange::openInputFile(const std::string& fileName, std::ifstream &inputFile)
{
	inputFile.open(fileName);
	if (inputFile.is_open() == false)
		throw std::ifstream::failure("Error: could not open file.");
}

void	BitcoinExchange::readInputFile(std::ifstream &inputFile)
{
	std::string		line;

	std::getline(inputFile, line);
	if (line != "date | value")
		throw (BadInput("Input file must start with 'date | value'"));
	while (inputFile.eof() == false)
	{
		std::getline(inputFile, line);
		this->input.insert(makeInputPair(line));
	}
	// std::multimap<std::string, float>::iterator itr = this->input.begin();
	// for(; itr != this->input.end(); itr++)
	// 	std::cout << itr->first << " | " << itr->second << std::endl;
}

std::pair<std::string, float>	BitcoinExchange::makeInputPair(const std::string &line)
{
	std::string	date;
	std::string	value;

	if (line.size() < 14)
		throw (BadInput(line));
	date = line.substr(0, 10);
	value = line.substr(13);
	if (isValidDate(date) == false)
		throw (NotValidDate(date));
	if (isValidValue(value) == false)
		throw (NotValidValue(value));
	return std::make_pair(date, convertFloat(value));
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	(void)date;
	return true;
}

bool	BitcoinExchange::isValidValue(const std::string& value)
{
	(void)value;
	return true;
}