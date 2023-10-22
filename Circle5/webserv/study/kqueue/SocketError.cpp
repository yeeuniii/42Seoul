#include "SocketError.hpp"

SocketError::SocketError(const char *message) : message(message) {}

const char* SocketError::what() const throw() {
	return this->message;
}