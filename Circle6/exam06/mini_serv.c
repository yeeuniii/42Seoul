#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <stdio.h>

struct serv_info {
    int CLIENT_ID;
    int MAX_FD;
    int listen_socket;
    fd_set readfds;
    fd_set cpy_readfds;
};

void setup(char* argv[], struct serv_info *serv);
void run(struct serv_info serv);
void handle_event(int fd, struct serv_info *serv);
void handle_read(int fd, struct serv_info *serv);

void print(int fd, char* message) {
    write(fd, message, strlen(message));
}

void print_error(char* message) {
    print(2, message);
    exit(1);
}

int main(int argc, char* argv[]) {
    struct serv_info serv;

    if (argc == 1) {
        print_error("Wrong number of arguments\n");
    }
    setup(argv, &serv);
    run(serv);
}

void setup(char* argv[], struct serv_info *serv) {
    int port;
    int listen_socket;
    struct sockaddr_in server_addr;
    
    port = atoi(argv[1]);
    serv->CLIENT_ID = 0;
    serv->listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (serv->listen_socket == -1) {
        print_error("Fatal error\n");
    }
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(2130706433);
    server_addr.sin_port = htons(port);
    if (bind(serv->listen_socket, (const struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        print_error("Fatal error\n"); 
    }
    if (listen(serv->listen_socket, 10) != 0) {
        print_error("Fatal error\n"); 
    }
}

void run(struct serv_info serv) {
    int number_of_fds = 0;
    // 시간 설정 필요
    
    FD_ZERO(&serv.readfds);
    FD_SET(serv.listen_socket, &serv.readfds);
    serv.MAX_FD = serv.listen_socket; // read에 한해서만

    while (number_of_fds != -1) {
        serv.cpy_readfds = serv.readfds;

        number_of_fds = select(serv.MAX_FD + 1, &serv.cpy_readfds, NULL, NULL, NULL);
        

        for (int fd = 0; number_of_fds > 0 && fd < serv.MAX_FD + 1; fd++) {
            handle_event(fd, &serv);
        }
    }
    if (number_of_fds == -1) {
        print_error("Fatal error\n");
    }
    exit(0);
}

void handle_event(int fd, struct serv_info *serv) {
    if (FD_ISSET(fd, &serv->cpy_readfds)) {
        handle_read(fd, serv);
    }
}

void handle_read(int fd, struct serv_info *serv) {
    int client_socket;
    socklen_t client_addr_len;
    struct sockaddr_in client_addr;
    char message[100];

    if (fd == serv->listen_socket) {
        client_addr_len = sizeof(client_addr);
        client_socket = accept(serv->listen_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            print_error("Fatal error\n"); 
        }
        sprintf(message, "server: client %d just arrived\n", serv->CLIENT_ID);
        serv->CLIENT_ID++;
        print(client_socket, message); // 모든 클라이언트에게 전송해야 함
        FD_SET(client_socket, &serv->readfds);
    }
    // client
    // read(idx, )
}

