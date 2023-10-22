#include "Connection.hpp"
#include "SocketError.hpp"
#include <sys/errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

Connection::KqueueError::KqueueError(const char *message) : message(message) {}

const char* Connection::KqueueError::what() const throw() {
	return this->message;
}

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
	}
	return *this;
}

Connection::~Connection() {}

void Connection::run() {
	_kqueue = kqueue();
	if (_kqueue == -1)
		throw(strerror(errno));
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
	}

}

void Connection::processListenEvent(const struct kevent& event) {
	if ((event.ident == _listen_socket && event.filter == EVFILT_READ) == false) 
		return ;

	struct sockaddr_in client_address;
	socklen_t client_address_len = sizeof(client_address);
	int server_socket = accept(_listen_socket, (struct sockaddr*)&client_address, &client_address_len);
	
	if (server_socket == -1)
		throw(SocketError(strerror(errno)));
	addEventToChangeList(server_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	addEventToChangeList(server_socket, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
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