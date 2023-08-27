#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main()
{
	static Serializer serializer;
	Data*	data = new Data;

	data->data = "asdf";

	Data*	rtv = serializer.deserialize(serializer.serialize(data));

	std::cout << data << std::endl;
	std::cout << rtv << std::endl;
	
	std::cout << data->data << std::endl;
	std::cout << rtv->data << std::endl;
	return 0;
}