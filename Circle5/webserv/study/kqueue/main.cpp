#include "SocketError.hpp"
#include "Connection.hpp"
#include <iostream>

int openListenSocket();

int	main(void)
{
	try
	{
		int listen_socket = openListenSocket();
		Connection connection(listen_socket);

		connection.run();
	}
	catch(const char* error_message)
	{
		std::cerr << error_message << std::endl;
		return 1;
	}
	return 0;
}
