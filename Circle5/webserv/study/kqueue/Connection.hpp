#ifndef __CONNECTION_HPP__
#define __CONNECTION_HPP__

#include <vector>
#include <sys/event.h>
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

	Connection();

	class KqueueError : public std::exception
	{
	private:
		const char *message;

	public:
		KqueueError(const char *message);
		virtual const char *what() const throw();
	};

	void addEventToChangeList(
		uintptr_t ident,
		int16_t filter,
		uint16_t flags,
		uint32_t fflags,
		intptr_t data,
		void *udata);
	void processEvents(const int& times);
	void processListenEvent(const struct kevent& evnet);
	void processReadEvent(const struct kevent& evnet);
	void processWriteEvent(const struct kevent& evnet);

public:
	Connection(int socket);
	Connection(const Connection &other);
	Connection operator=(const Connection &other);
	~Connection();

	void run();
};

#endif