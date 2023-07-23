#ifndef __Sed_HPP__
#define __Sed_HPP__

#include <string>

class Sed
{
    private:
        std::string fileName;
		std::string	oldValue;
		std::string	newValue;
		
		void		openFile(std::ifstream &file_stream);
		void		openFile(std::ofstream &file_stream);
		std::string	readFile();
		void		writeFile(std::string write_content);
		std::string	replace(std::string file_content);

	public:
		Sed(std::string file_name, std::string old_value, std::string new_value);

		void	execute();
		static void	display_manual();
		
};

#endif