#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main()
{
	static Serializer serializer;
	Data*	data = new Data;

	data->data = "data";

	Data*	rtv = serializer.deserialize(serializer.serialize(data));

	std::cout << "----------Address----------" << std::endl;
	std::cout << "Original : " << data << std::endl;
	std::cout << "Return value : " << rtv << std::endl;

	std::cout << std::endl;	
	std::cout << "----------data member----------" << std::endl;
	std::cout << "Original : " << data->data << std::endl;
	std::cout << "Return value : " << rtv->data << std::endl;

	delete data;
	return 0;
}