#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <cstdio>

enum class LOG_LEVEL
{
	LOG,
	WARNING,
	ERROR
};
class Logger
{
public:
	static void Log(LOG_LEVEL level, std::string message);

	static void LogPrintf(LOG_LEVEL level, std::string message, ...);

private:
	static std::string BuildMessage(LOG_LEVEL level, std::string message);
};

#endif
