#include "SocketError.hpp"
#include <iostream>

int openListenSocket();

int	main(void)
{
	try
	{
		int listen_socket = openListenSocket();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
