#include "Sed.hpp"
#include <iostream>
#include <fstream>

Sed::Sed(std::string file_name, std::string old_value, std::string new_value)
{
	this->fileName = file_name;
	this->oldValue = old_value;
	this->newValue = new_value;
}

void	Sed::display_manual() 
{
	std::cout << "If you want to use the replace command in sed, enter it as follows." << std::endl;
	std::cout << std::string(44, '-') << std::endl;
	std::cout << "| ./sed <filename> <old_value> <new_value> |" << std::endl; 
	std::cout << std::string(44, '-') << std::endl;
}

void	Sed::openFile(std::ifstream &file_stream)
{
	file_stream.open(this->fileName);
	if (!file_stream.is_open())
	{
		std::cout << this->fileName << "is not open." << std::endl;
		exit(0);
	}
}

std::string	Sed::readFile()
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


void	Sed::replace()
{
	std::string	file_content;

	file_content = readFile();
	//std::cout << file_content << std::endl;
}