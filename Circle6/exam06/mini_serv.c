#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

struct server {
    int listen_socket;
    fd_set selectfds;
    fd_set readfds;
    fd_set writefds;
    int max_fd;
    int number_of_clients;
    int clients[65536];
    char* buf[65536];
};


/* prototype */

void init_server(struct server* server);
void setup(int port, struct server* server);
void run(struct server server);
void process_ready_fds(int fd, struct server* server);
void connect_client(int fd, struct server* server);
void register_client(int fd, struct server* server);
void recv_message_from_client(int fd, struct server* server);
void remove_client(int fd, struct server* server);
void send_message(int fd, struct server* server);
void send_message_to_others(int my, char* message, struct server server);
void print_error(char* message);
int extract_message(char **buf, char **msg);
char *str_join(char *buf, char *add);


/* main */

int main(int argc, char *argv[]) {
    struct server server;

    if (argc != 2) {
        print_error("Wrong number of arguments\n");
    }
    setup(atoi(argv[1]), &server);
    run(server);
}


/* create listen socket */
void init_server(struct server* server) {
    server->number_of_clients = 0;
    server->listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->listen_socket == -1) {
        print_error("Fatal error\n");
    }
    server->max_fd = server->listen_socket;
    bzero(&server->clients, sizeof(server->clients));
}

void setup(int port, struct server* server) {
    struct sockaddr_in server_addr;

    init_server(server);
    bzero(&server_addr, sizeof(server_addr)); 
	server_addr.sin_family = AF_INET; 
	server_addr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	server_addr.sin_port = htons(port);

    if (bind(server->listen_socket, (const struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        print_error("Fatal error\n");
    }
    if (listen(server->listen_socket, 10)) {
        print_error("Fatal error\n");
    }
}

/* multiplexing */
void run(struct server server) {
    int number_of_fds = 0;

    FD_ZERO(&server.selectfds);
    FD_SET(server.listen_socket, &server.selectfds);

    while (number_of_fds != -1) {
        server.readfds = server.selectfds;
        server.writefds = server.selectfds;

        number_of_fds = select(server.max_fd + 1, &server.readfds, &server.writefds, NULL, NULL);

        for (int fd = 0; number_of_fds > 0 && fd < server.max_fd + 1; fd++) {
            if (FD_ISSET(fd, &server.readfds)) {
                process_ready_fds(fd, &server);
            }
        }
    }
    if (number_of_fds == -1) {
        print_error("Fatal error\n");
    }
}

void process_ready_fds(int fd, struct server* server) {
    if (fd == server->listen_socket) {
        connect_client(fd, server);
    }
    else {
        recv_message_from_client(fd, server);
    }
}

/* 1. listen socket */
void connect_client(int fd, struct server* server) {
    int connection_socket;
    socklen_t client_addr_len;
    struct sockaddr_in client_addr;

    client_addr_len = sizeof(client_addr);    
    connection_socket = accept(server->listen_socket, (struct sockaddr *)&client_addr, &client_addr_len);
    if (connection_socket < 0) {
        print_error("Fatal error\n");
    }
    register_client(connection_socket, server);
}

void register_client(int fd, struct server* server) {
    char message[65536];

    server->clients[fd] = server->number_of_clients++;
    server->buf[fd] = NULL;
    FD_SET(fd, &server->selectfds);
    if (fd > server->max_fd) {
        server->max_fd = fd;
    }
    sprintf(message, "server: client %d just arrived\n", server->clients[fd]);
    send_message_to_others(fd, message, *server);
}


/* 2. client */
void recv_message_from_client(int fd, struct server* server) {
    char buffer[65536];
    int read_byte;

    read_byte = recv(fd, buffer, 65536, 0);
    if (read_byte < 1) {
        remove_client(fd, server);
        return;
    }
    buffer[read_byte] = '\0';
    server->buf[fd] = str_join(server->buf[fd], buffer);
    if (!server->buf[fd]) {
        print_error("Fatal error\n");
    }
    send_message(fd, server);
}

void remove_client(int fd, struct server* server) {
    char message[65536];
    
    FD_CLR(fd, &server->selectfds);
    close(fd);
    free(server->buf[fd]);
    sprintf(message, "server: client %d just left\n", server->clients[fd]);
    send_message_to_others(fd, message, *server);
}

void send_message(int fd, struct server* server) {
    int status;
    char* line;
    char message[65536];

    while ((status = extract_message(&server->buf[fd], &line)) > 0) {
        sprintf(message, "client %d: %s", server->clients[fd], line);
        send_message_to_others(fd, message, *server);
    }
    if (status == -1) {
        print_error("Fatal error\n");
    }
}


/* utils */
void send_message_to_others(int my, char* message, struct server server) {
    for (int fd = 0; fd < server.max_fd + 1; fd++) {
        if (FD_ISSET(fd, &server.writefds) && fd != my) {
            send(fd, message, strlen(message), 0);
        }
    }
}

void print_error(char* message) {
    write(2, message, strlen(message)); 
    exit(1);
}


/* given functions */
int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}