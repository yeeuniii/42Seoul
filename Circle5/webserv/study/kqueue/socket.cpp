#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "SocketError.hpp"

#define PORT 8080
// #define IP 127.0.0.1

int openListenSocket() {
	int	listen_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in server_address;

	memset((void*)&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(listen_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) 
		throw (SocketError("Fail bind a socket"));
	if (listen(listen_socket, 5) == -1) 
		throw (SocketError("Fail listen a client"));
	return listen_socket;
}