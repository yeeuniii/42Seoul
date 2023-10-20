#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#define PORT 8080
#define IP 127.0.0.1
#define BUFFER_SIZE 10000

int	main(void)
{
	int	sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in server_address;

	memset((void*)&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
		std::cout << "Fail bind a socket\n";
		return 1;
	}
	if (listen(sockfd, 5) == -1) {
		std::cout << "Fail listen\n";
		return -1;
	}

	struct sockaddr_in client_address;
	socklen_t client_address_len = sizeof(client_address);
	int n;
	while (1) {
		int new_sockfd = accept(sockfd, (struct sockaddr*)&client_address, &client_address_len);
		char buff[BUFFER_SIZE];

		if (new_sockfd == -1) {
			std::cout << "fail" << std::endl;
		}
		std::cout << "original fd : " << sockfd << std::endl;
		std::cout << "new socket fd : " << new_sockfd << std::endl;
		memset(buff, 0, sizeof(buff));
		while ((n = read(new_sockfd, &buff, BUFFER_SIZE)) > 0) {

			std::cout << "request : " << buff << std::endl;
			*buff = '1';
			write(new_sockfd, buff, strlen(buff) + 1);
			memset(buff, 0, sizeof(buff));
		}
		close(new_sockfd);
	}
	return 0;
}
