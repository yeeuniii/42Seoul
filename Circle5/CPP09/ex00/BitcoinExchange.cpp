#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>

const char* BitcoinExchange::InvalidDatabase::what() const throw()
{
	return "Error: invalid database format";
}

BitcoinExchange::BadInput::BadInput() {}

BitcoinExchange::BadInput::BadInput(const std::string& detail)
{
	this->message = "Error: " + detail;
}

BitcoinExchange::BadInput::~BadInput() throw() {}

const char* BitcoinExchange::BadInput::what() const throw()
{
	return this->message.c_str();
}

BitcoinExchange::InvalidDate::InvalidDate(const std::string& detail) : BadInput()
{
	this->message = "Error: non-existent date => " + detail;
}

BitcoinExchange::InvalidDateFormat::InvalidDateFormat(const std::string& detail) : BadInput()
{
	this->message = "Error: invalid date format(Year-Month-Day) => " + detail;
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
	message = "Error: invalid value format(a float or a positive integer) => " + detail;
}

const char* BitcoinExchange::NotExistDate::what() const throw()
{
	return "Error: does not match the date in the database.";
}

BitcoinExchange::BitcoinExchange() {}
		
BitcoinExchange::BitcoinExchange(const BitcoinExchange& bitcoinExchange)
{
	*this = bitcoinExchange;
}

BitcoinExchange::~BitcoinExchange() {std::cout << "destruct" << std::endl;}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& bitcoinExchange)
{
	if (this != &bitcoinExchange)
	{
	}
	return *this;
}

void	BitcoinExchange::run(const std::string& fileName)
{
	std::map<std::string, float>	data;
	
	try
	{
		readDataBase(data);
		processInput(fileName, data);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	BitcoinExchange::readDataBase(std::map<std::string, float>& data)
{
	std::ifstream	database;
	char			delimiter;
	std::string		line;

	database.open(DB);
	if (database.is_open() == false)
		throw std::ifstream::failure("Error: could not open file.");	
	delimiter = findDelimiter(database);
	std::cout << "delimiter : " << delimiter << std::endl;
	while (database.eof() == false)
	{
		std::getline(database, line);
		checkDatabaseFormat(line, delimiter);
		data.insert(std::make_pair(line.substr(0, 10), convertFloat(line.substr(11))));
	}
	database.close();
}

char	BitcoinExchange::findDelimiter(std::ifstream& database)
{
	std::string	line;
	char 		delimiter;

	std::getline(database, line);
	if (line.find("date") == std::string::npos)
		throw(InvalidDatabase());
	line = line.substr(4);
	delimiter = line[0];
	line = line.substr(1);
	if (line != "exchange_rate")
		throw(InvalidDatabase());
	return delimiter;
}

void	BitcoinExchange::checkDatabaseFormat(const std::string& line, const char& delimiter)
{
	std::string		date;
	std::string		rate;

	if (line.find(delimiter) == std::string::npos)
		throw (InvalidDatabase());
	date = line.substr(0, 10);
	if (isValidDate(date) == false)
		throw (InvalidDate(date));
	rate = line.substr(11);
	checkValueFormat(rate);
}

void	BitcoinExchange::processInput(
	const std::string& fileName,
	std::map<std::string, float>& data)
{	
	std::ifstream	inputFile;
	std::string		line;

	openInputFile(fileName, inputFile);
	std::getline(inputFile, line);
	if (line != "date | value")
		throw (BadInput("the input file should start with 'date | value'."));
	while (inputFile.eof() == false)
	{
		processOneLine(inputFile, data);
	}
	inputFile.close();
}

void	BitcoinExchange::processOneLine(
	std::ifstream& inputFile,
	std::map<std::string, float>& data)
{
	std::string						line;
	std::pair<std::string, float>	input;
	float							result;
	
	try
	{
		std::getline(inputFile, line);
		if (line.empty())
		{
			std::cout << std::endl;
			return ;
		}
		input = makeInputPair(line);
		result = multipleValueAndRate(input, data);
		std::cout << input.first << " => " << input.second << " = " << result << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	BitcoinExchange::openInputFile(const std::string& fileName, std::ifstream &inputFile)
{
	inputFile.open(fileName.c_str());
	if (inputFile.is_open() == false)
		throw std::ifstream::failure("Error: could not open file.");
}

std::pair<std::string, float>	BitcoinExchange::makeInputPair(const std::string &line)
{
	std::stringstream	ss(line);
	std::string			date;
	std::string			value;

	ss >> date;
	ss >> value;
	if (value != "|")
		throw (BadInput("bad input => " + line));
	ss >> value;
	if (isValidDate(date) == false)
		throw (InvalidDate(date));
	checkValidValue(value);
	return std::make_pair(date, convertFloat(value));
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	int	year = convertInteger(date.substr(0, 4));
	int	month = convertInteger(date.substr(5, 2));
	int	day = convertInteger(date.substr(8, 2));
	int	endOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isDateFormat(date) == false)
		throw (InvalidDateFormat(date));
	if ((year % 4 == 0 && year % 100) || year % 400 == 0)
		endOfMonth[1] = 29;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > endOfMonth[month - 1])
		return false;
	return true;
}

bool	BitcoinExchange::isDateFormat(const std::string& date)
{
	unsigned int idx = 0;

	if (date.size() != 10)
		return false;
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

void	BitcoinExchange::checkValidValue(const std::string& valueString)
{
	float	value;

	checkValueFormat(valueString);
	value = convertFloat(valueString);
	if (value < 0)
		throw (NegativeValue());
	if (value > 1000)
		throw (TooLargeValue());
}

void	BitcoinExchange::checkValueFormat(const std::string& value)
{
	if (isFloatString(value) == false)
		throw (InvalidValueFormat(value));
}

float	BitcoinExchange::multipleValueAndRate(
	const std::pair<std::string, float>& input,
	std::map<std::string, float>& data)
{
	std::map<std::string, float>::iterator	itr = data.begin();

	while (itr != data.end() && input.first >= itr->first)
		itr++;
	if (itr == data.begin())
		throw (NotExistDate());
	itr--;
	return input.second * itr->second;
}


bool	isFloatString(const std::string& string)
{
	int	idx = 0;
	int	size = string.size();

	if (string[0] == '-' || string[0] == '+')
		idx++;
	while (idx < size && isdigit(string[idx]))
		idx++;
	if (string[idx] == '.' && idx != size - 1)
		idx++;
	while (idx < size && isdigit(string[idx]))
		idx++;
	return idx == size;
}

float	convertFloat(const std::string& string)
{
	std::stringstream ss;
	float	_float;
	
	ss << string;
	ss >> _float;
	return _float;
}

int		convertInteger(const std::string& string)
{
	std::stringstream	ss;
	int		_int;

	ss << string;
	ss >> _int;
	return _int;
}