#pragma once
#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>

#define WHITE "\e[0m"
#define RED "\e[0;31m"
#define BLUE "\e[0;34m"

int	convertStrToInt(std::string string);
int	isDigitString(std::string string);
int	isWhitespaceString(std::string string);

#endif
