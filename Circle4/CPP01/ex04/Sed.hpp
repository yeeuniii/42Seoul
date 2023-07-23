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
		std::string	readFile();
    
	public:
		Sed(std::string file_name, std::string old_value, std::string new_value);

		void	execute();
		std::string	replace(std::string file_content);
		static void	display_manual();
		
};

#endif