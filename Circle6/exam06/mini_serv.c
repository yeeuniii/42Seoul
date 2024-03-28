#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

void handle_error(char* message) {
    write(2, message, strlen(message));
    exit(1);
}


int main(int argc, char* argv[]) {
    int port, listen_socket, client_socket;
    socklen_t client_addr_len;
    struct sockaddr_in server_addr, client_addr;
    
    if (argc == 1) {
        handle_error("Wrong number of arguments\n");
    }
    port = atoi(argv[1]);
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        handle_error("Fatal error\n");
    }
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(2130706433);
    server_addr.sin_port = htons(port);
    if (bind(listen_socket, (const struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
       handle_error("Fatal error\n"); 
    }
    if (listen(listen_socket, 10) != 0) {
        handle_error("Fatal error\n"); 
    }
    client_addr_len = sizeof(client_addr);
    client_socket = accept(listen_socket, (struct sockaddr *)&client_socket, &client_addr_len);
    if (client_socket == -1) {
        handle_error("Fatal error\n"); 
    }
    exit(0);
}