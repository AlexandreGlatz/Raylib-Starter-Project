#include "pch.h"
#include "Logger.h"

#include <iostream>
#include <cstdarg>

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

void Logger::LogPrintf(LOG_LEVEL level, std::string message, ...)
{
	va_list args;

	va_start(args, message.c_str());
	std::string builtMessage = BuildMessage(level, message);
	std::vprintf(builtMessage.c_str(), args);
	va_end(args);
}

