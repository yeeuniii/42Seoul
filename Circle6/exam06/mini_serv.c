#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <stdio.h>

struct server {
    int listen_socket;
    fd_set readfds;
    fd_set writefds;
    fd_set selectfds;
    int clients[65536]; // fd -> id
    char* messages[65536];
    int number_of_client;
    int max_fd;
};

void setup(char* argv[], struct server *serv);
void run(struct server serv);
void handle_read(int fd, struct server *serv);
void register_client(struct server *serv);
void remove_client(int fd, struct server *serv);
void send_other_clients(char* message, int my, struct server serv);

/* given */

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

void print_error(char* message) {
    write(2, message, strlen(message));
    exit(1);
}

int main(int argc, char* argv[]) {
    struct server serv;

    if (argc == 1) {
        print_error("Wrong number of arguments\n");
    }
    setup(argv, &serv);
    run(serv);
}

void setup(char* argv[], struct server *serv) {
    int port;
    int listen_socket;
    struct sockaddr_in server_addr;
    
    port = atoi(argv[1]);
    serv->number_of_client = 0;
    serv->listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (serv->listen_socket == -1) {
        print_error("Fatal error\n");
    }
    bzero(&serv->clients, sizeof(serv->clients));
    bzero(&serv->messages, sizeof(serv->messages));
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

void run(struct server serv) {
    int number_of_fds = 0;
    
    FD_ZERO(&serv.selectfds);
    FD_SET(serv.listen_socket, &serv.selectfds);
    serv.max_fd = serv.listen_socket;

    while (number_of_fds != -1) {
        serv.readfds = serv.selectfds;
        serv.writefds = serv.selectfds;
        number_of_fds = select(serv.max_fd + 1, &serv.readfds, &serv.writefds, NULL, NULL);        

        for (int fd = 0; number_of_fds > 0 && fd < serv.max_fd + 1; fd++) {
            if (FD_ISSET(fd, &serv.readfds)) {
                handle_read(fd, &serv);
            }
        }
    }
    if (number_of_fds == -1) {
        print_error("Fatal error\n");
    }
    exit(0);
}

void handle_read(int fd, struct server *serv) {
    if (fd == serv->listen_socket) {
        register_client(serv);
        return ;
    }

    char buffer[65536];
    int read_byte = recv(fd, &buffer, 65536, 0); 
    
    if (read_byte < 1) {
        remove_client(fd, serv);
        return ;
    }
    buffer[read_byte] = '\0';
    serv->messages[fd] = str_join(serv->messages[fd], buffer);
    
    int status;
    char message[65536];
    char* line;
    while ((status = extract_message(&serv->messages[fd], &line)) > 0) {
        sprintf(message, "client %d: %s", serv->clients[fd], line);
        send_other_clients(message, fd, *serv);
    }
    if (status == -1) {
        print_error("Fatal error\n");
    }
}

void register_client(struct server *serv) {
    int client_socket;
    socklen_t client_addr_len;
    struct sockaddr_in client_addr;
    char message[65536];
    
    client_addr_len = sizeof(client_addr);
    client_socket = accept(serv->listen_socket, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket == -1) {
        print_error("Fatal error\n"); 
    }
    FD_SET(client_socket, &serv->selectfds);
    if (serv->max_fd < client_socket) {
        serv->max_fd = client_socket;
    }
    serv->clients[client_socket] = serv->number_of_client++;
    serv->messages[client_socket] = NULL;
    sprintf(message, "server: client %d just arrived\n", serv->clients[client_socket]);
    send_other_clients(message, client_socket, *serv);
}

void remove_client(int fd, struct server *serv) {
    char message[65536];
    
    FD_CLR(fd, &serv->selectfds);
    close(fd);
    free(serv->messages[fd]);
    sprintf(message, "server: client %d just left\n", serv->clients[fd]);
    send_other_clients(message, fd, *serv);
}

void send_other_clients(char* message, int my, struct server serv) {
    for (int fd = 0; fd < serv.max_fd + 1; fd++) {
        if (FD_ISSET(fd, &serv.writefds) && fd != my) {
            send(fd, message, strlen(message), 0);
        }
    }
}
