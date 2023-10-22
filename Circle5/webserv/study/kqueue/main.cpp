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
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
