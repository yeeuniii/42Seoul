#include "Connection.hpp"
#include "SocketError.hpp"
#include <sys/errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>

Connection::Connection() {}

Connection::Connection(int socket) {
	_kqueue = kqueue();
	memset(_event_list, 0, sizeof(struct kevent) * NUMBER_OF_EVENT);
	_listen_socket = socket;
}

Connection::Connection(const Connection &other) {
	*this = other;
}

Connection Connection::operator=(const Connection &other) {
	if (this != &other) {
		_change_list = other._change_list;
		memset(_event_list, 0, sizeof(struct kevent) * NUMBER_OF_EVENT);
		for (int idx = 0; idx < NUMBER_OF_EVENT; idx++)
			_event_list[idx] = other._event_list[idx];
		_listen_socket = other._listen_socket;
		_clients = other._clients;
	}
	return *this;
}

Connection::~Connection() {}

void Connection::run() {
	_kqueue = kqueue();
	if (_kqueue == -1)
		throw(errno);
	addEventToChangeList(_listen_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	while (1) {
		memset(_event_list, 0, sizeof(struct kevent) * NUMBER_OF_EVENT);
		int times = kevent(_kqueue, &(_change_list[0]), _change_list.size(), _event_list, NUMBER_OF_EVENT, 0);
		_change_list.clear();
		/* return value에 따른 처리 */

		processEvents(times);
	}
}

void Connection::processEvents(const int& times) {
	for (int idx = 0; idx < times; idx++) {
		struct kevent event = _event_list[idx];

		processListenEvent(event);
		processReadEvent(event);
		processWriteEvent(event);
	}
}

void Connection::processListenEvent(const struct kevent& event) {
	if ((event.ident == _listen_socket && event.filter == EVFILT_READ) == false) 
		return ;

	struct sockaddr_in client_address;
	socklen_t client_address_len = sizeof(client_address);
	int server_socket = accept(_listen_socket, (struct sockaddr*)&client_address, &client_address_len);
	
	if (server_socket == -1)
		throw(strerror(errno));
	_clients[server_socket] = "";
	addEventToChangeList(server_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	addEventToChangeList(server_socket, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
	printf("Connet with socket %d\n", server_socket);
}
	
void Connection::processReadEvent(const struct kevent& event) {
	if ((_clients.find(event.ident) != _clients.end() && event.filter == EVFILT_READ) == false) 
		return ;

	int n;
	char buff[BUFFER_SIZE];
	
	memset(buff, 0, sizeof(buff));
	while ((n = read(event.ident, &buff, BUFFER_SIZE)) == BUFFER_SIZE) {
		_clients[event.ident] += buff;
		memset(buff, 0, sizeof(buff));
	}
	if (n == -1)
		throw(strerror(errno));	
	if (n > 0)
		buff[n] = 0;
	_clients[event.ident] += buff;
	printf("Read in socket %lu : %s", event.ident, _clients[event.ident].c_str());
}

void Connection::processWriteEvent(const struct kevent& event) {
	if ((_clients.find(event.ident) != _clients.end() && event.filter == EVFILT_WRITE) == false || _clients[event.ident] == "")
		return ;

	int n =write(event.ident, _clients[event.ident].c_str(), _clients[event.ident].size());

	if (n == -1)
		throw(strerror(errno));	
	_clients[event.ident].clear();
}

void Connection::addEventToChangeList(
	uintptr_t ident,
	int16_t filter,
	uint16_t flags,
	uint32_t fflags,
	intptr_t data,
	void* udata) {
	struct kevent event;
	
	EV_SET(&event, ident, filter, flags, fflags, data, udata);
	_change_list.push_back(event);
}