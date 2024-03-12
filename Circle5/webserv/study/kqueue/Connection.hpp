#ifndef __CONNECTION_HPP__
#define __CONNECTION_HPP__

#include <sys/event.h>
#include <map>
#include <vector>
#include <string>
#include <exception>

#define BUFFER_SIZE 10000
#define NUMBER_OF_EVENT 8

class Connection
{
private:
	int _kqueue;
	std::vector<struct kevent> _change_list;
	struct kevent _event_list[NUMBER_OF_EVENT];
	int _listen_socket;
	std::map<int, std::string> _clients;

	Connection();

	void processWriteEvent(const struct kevent& event);
	void processEvents(const int& times);
	void checkEventError(const struct kevent& event);
	void processListenEvent(const struct kevent& event);
	void processReadEvent(const struct kevent& event);
	
	void addEventToChangeList(
		uintptr_t ident,
		int16_t filter,
		uint16_t flags,
		uint32_t fflags,
		intptr_t data,
		void *udata);
	void disconnectWithClient(const struct kevent& event);

public:
	Connection(int socket);
	Connection(const Connection &other);
	Connection operator=(const Connection &other);
	~Connection();

	void run();
};

#endif