#ifndef Sed_HPP
#define Sed_HPP

#include <string>

class Sed
{
    private:
        std::string fileName;
		std::string	oldValue;
		std::string	newValue;
		
		void		openFile(std::ifstream &file_stream);
		std::string	readFile();
    
	public:
		Sed(std::string file_name, std::string old_value, std::string new_value);

		void	replace();
		static void	display_manual();
		
};

#endif