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

	template <class ... Args>
	static void LogPrintf(LOG_LEVEL level, std::string message, Args ... args);

private:
	static std::string BuildMessage(LOG_LEVEL level, std::string message);
};

#endif

template<class ...Args>
inline void Logger::LogPrintf(LOG_LEVEL level, std::string message, Args ...args)
{
	std::string builtMessage = BuildMessage(level, message);
	std::printf(builtMessage, args);
}
