#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#define PORT 8080
#define BUFFER_SIZE 10000

int	main(void)
{
	struct sockaddr_in client_address;

	memset((void*)&client_address, 0, sizeof(client_address));
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(PORT);
	client_address.sin_addr.s_addr = htonl(INADDR_ANY);

	int	sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	if (connect(sockfd, (struct sockaddr*)&client_address, sizeof(client_address)) == -1) {
		std::cout << "Fail connect\n";
		return -1;
	}
	while (1)
	{
		char buff[BUFFER_SIZE];
		
		memset(buff, 0, sizeof(buff));
		read(0, &buff, BUFFER_SIZE);
		write(sockfd, buff, strlen(buff));
		read(sockfd, &buff, BUFFER_SIZE);
		std::cout << "response : " << buff << std::endl;
	}
	//close(sockfd);
	return 0;
}
