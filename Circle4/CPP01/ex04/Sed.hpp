#ifndef __Sed_HPP__
#define __Sed_HPP__

#include <string>

class Sed
{
    private:
    	const std::string	fileName;
		const std::string	oldValue;
		const std::string	newValue;
		
		void		openFile(std::ifstream &file_stream) const;
		void		openFile(std::ofstream &file_stream) const;
		void		handleOpenError(int isError) const;
		std::string	readFile() const;
		void		writeFile(std::string write_content) const;
		std::string	replace(std::string file_content) const;

	public:
		Sed(std::string file_name, std::string old_value, std::string new_value);

		void	execute() const;
};

#endif
