#include "pch.h"
#include "Logger.h"

#include <iostream>

void Logger::Log(LOG_LEVEL level, std::string message)
{

	std::cout << BuildMessage(level, message) << std::endl;
}

std::string Logger::BuildMessage(LOG_LEVEL level, std::string message)
{
	std::string prefix;

	switch (level)
	{
	case LOG_LEVEL::LOG:
		prefix = "[LOG] : ";
		break;
	case LOG_LEVEL::WARNING:
		prefix = "[WARN] : ";
		break;
	case LOG_LEVEL::ERROR:
		prefix = "[ERR] : ";
		break;
	}

	return prefix + message;
}
