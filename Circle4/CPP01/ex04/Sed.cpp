#include "Sed.hpp"
#include <ios>
#include <iostream>
#include <fstream>

Sed::Sed(std::string file_name, std::string old_value, std::string new_value): 
	fileName(file_name), oldValue(old_value), newValue(new_value) {}

void	Sed::display_manual()
{
	std::cout << "Enter the following, if you execute replace of sed command." << std::endl;
	std::cout << std::string(44, '-') << std::endl;
	std::cout << "| ./sed <filename> <old_value> <new_value> |" << std::endl; 
	std::cout << std::string(44, '-') << std::endl;
}

void	Sed::openFile(std::ifstream &file_stream) const
{
	file_stream.open(this->fileName);
	if (!file_stream.is_open())
	{
		std::cout << this->fileName << "is not open." << std::endl;
		exit(0);
	}
}

void	Sed::openFile(std::ofstream &file_stream) const
{
	file_stream.open(this->fileName + ".replace", std::ios::trunc);
	if (!file_stream.is_open())
	{
		std::cout << this->fileName << "is not open." << std::endl;
		exit(0);
	}
}

std::string	Sed::readFile() const
{
	std::ifstream	input_stream;
	std::string		read_value;
	std::string		file_content;

	openFile(input_stream);
	while (!input_stream.eof())
	{
		std::getline(input_stream, read_value);
		file_content += read_value;
		file_content += "\n";
	}
	file_content.pop_back();
	return file_content;
}

std::string	Sed::replace(std::string file_content) const
{
	std::string	replace_content;
	int			index;

	index = file_content.find(this->oldValue);
	while (index != -1)
	{
		replace_content += file_content.substr(0, index);
		replace_content += this->newValue;
		file_content = file_content.substr(index + this->oldValue.size());
		index = file_content.find(this->oldValue);
	}
	replace_content += file_content.substr(0, index);
	return replace_content;
}

void	Sed::writeFile(std::string write_content) const 
{
	std::ofstream	output_stream;

	openFile(output_stream);
	output_stream.write(write_content.c_str(), write_content.size());
}

void	Sed::execute() const
{
	std::string	file_content;

	file_content = readFile();
	writeFile(replace(file_content));
}