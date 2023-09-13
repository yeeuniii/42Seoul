#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <cstring>

BitcoinExchange::BadInput::BadInput() : message("") {}

BitcoinExchange::BadInput::BadInput(const std::string& detail)
{
	std::string	message;

	message = "Error: " + detail;
	this->message = message.c_str();
}

const char* BitcoinExchange::BadInput::what() const throw()
{
	return this->message;
}

BitcoinExchange::InvalidDate::InvalidDate(const std::string& detail) : BadInput(detail)
{
	std::string	message;

	message = "Error: non-existent date => " + detail;
	this->message = message.c_str();
}

BitcoinExchange::InvalidDateFormat::InvalidDateFormat(const std::string& detail) : BadInput(detail)
{
	std::string	message;

	message = "Error: invalid date format(Year-Month-Day) => " + detail;
	this->message = message.c_str();
}

BitcoinExchange::NegativeValue::NegativeValue() : BadInput() {}

const char*	BitcoinExchange::NegativeValue::what() const throw()
{
	return "Error: not a positive number.";
}

BitcoinExchange::TooLargeValue::TooLargeValue() : BadInput() {}

const char*	BitcoinExchange::TooLargeValue::what() const throw()
{
	return "Error: too large a number.";
}

BitcoinExchange::InvalidValueFormat::InvalidValueFormat(const std::string& detail) : BadInput(detail)
{
	std::string	message("Error: invalid value format(a float or a positive integer) => ");

	message += detail;
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


void	BitcoinExchange::handleInputFile(const std::string& fileName)
{
	std::ifstream	inputFile;

	openInputFile(fileName, inputFile);
	readInputFile(inputFile);
	inputFile.close();
}

void	BitcoinExchange::openInputFile(const std::string& fileName, std::ifstream &inputFile) const
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
		throw (BadInput("input file must start with 'date | value'"));
	while (inputFile.eof() == false)
	{
		std::getline(inputFile, line);
		this->input.insert(makeInputPair(line));
	}
	// std::multimap<std::string, float>::iterator itr = this->input.begin();
	// for(; itr != this->input.end(); itr++)
	// 	std::cout << itr->first << " | " << itr->second << std::endl;
}

std::pair<std::string, float>	BitcoinExchange::makeInputPair(const std::string &line) const
{
	std::string	date;
	std::string	value;

	if (line.size() < 14)
		throw (BadInput("bad input => " + line));
	date = line.substr(0, 10);
	value = line.substr(13);
	if (isValidDate(date) == false)
		throw (InvalidDate(date));
	checkValidValue(value);
	return std::make_pair(date, convertFloat(value));
}

bool	BitcoinExchange::checkDateFormat(const std::string& date) const
{
	unsigned int idx = 0;

	// if (date.size() != 10)
	// 	return false;
	while (idx < 4 && isdigit(date[idx]))
		idx++;
	if (idx != 4 || date[idx++] != '-')
		return false;
	while (idx < 7 && isdigit(date[idx]))
		idx++;
	if (idx != 7 || date[idx++] != '-')
		return false;
	while (idx < 10 && isdigit(date[idx]))
		idx++;
	return idx == 10;
}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	int	year = convertInteger(date.substr(0, 4));
	int	month = convertInteger(date.substr(5, 2));
	int	day = convertInteger(date.substr(8, 2));
	int	endOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (checkDateFormat(date) == false)
		throw (InvalidDateFormat(date));
	if ((year % 4 == 0 && year % 100) || year % 400 == 0)
		endOfMonth[1] = 29;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > endOfMonth[month - 1])
		return false;
	return true;
}

bool	BitcoinExchange::checkValueFormat(const std::string& value) const
{
	int	idx = 0;
	int	size = value.size();

	if (value[0] == '-')
		idx++;
	while (idx < size && isdigit(value[idx]))
		idx++;
	if (value[idx] == '.' && idx != size - 1)
		idx++;
	while (idx < size && isdigit(value[idx]))
		idx++;
	return idx == size;
}

void	BitcoinExchange::checkValidValue(const std::string& valueString) const
{
	float	value = convertFloat(valueString);

	if (checkValueFormat(valueString) == false)
		throw (InvalidValueFormat(valueString));
	if (value < 0)
		throw (NegativeValue());
	if (value > 1000)
		throw (TooLargeValue());
}

float	BitcoinExchange::convertFloat(std::string string) const
{
	std::stringstream ss;
	float	_float;
	
	ss << string;
	ss >> _float;
	return _float;
}

int	BitcoinExchange::convertInteger(std::string string) const
{
	std::stringstream	ss;
	int		_int;

	ss << string;	
	ss >> _int;
	return _int;
}