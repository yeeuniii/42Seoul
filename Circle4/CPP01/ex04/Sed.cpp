#include "Sed.hpp"
#include <ios>
#include <iostream>
#include <fstream>
#include <cstdlib>

Sed::Sed(std::string file_name, std::string old_value, std::string new_value): 
	fileName(file_name), oldValue(old_value), newValue(new_value) {}

void	Sed::handleOpenError(int isError) const
{
	if (isError)
	{
		std::cout << this->fileName << " is not open." << std::endl;
		exit(1);
	}
}

void	Sed::openFile(std::ifstream &file_stream) const
{
	file_stream.open(this->fileName.c_str());
	handleOpenError(!file_stream.is_open());
}

void	Sed::openFile(std::ofstream &file_stream) const
{
	file_stream.open((this->fileName + ".replace").c_str(), std::ios::trunc);
	handleOpenError(!file_stream.is_open());
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
	input_stream.close();
	file_content.resize(file_content.size() - 1);
	return file_content;
}

std::string	Sed::replace(std::string file_content) const
{
	std::string	replace_content;
	int			index;

	if (this->oldValue == this->newValue)
		return file_content;
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
	output_stream.close();
}

void	Sed::execute() const
{
	std::string	file_content;

	file_content = readFile();
	writeFile(replace(file_content));
}
