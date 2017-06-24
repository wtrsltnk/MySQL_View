#include "Log.h"
#include <iostream>

Log::Log(const std::string& type)
    : _type(type)
{ }

const char* logLevelsToString(LogLevels level)
{
    switch (level)
    {
    case LogLevels::Debug: return "DEBUG";
    case LogLevels::Error: return "ERROR";
    case LogLevels::Info: return "INFO";
    case LogLevels::Warning: return "WARNING";
    }
}

void Log::logMessage(LogLevels level, const std::string& message)
{
    if (level == LogLevels::Error)
        std::cerr << "[" << logLevelsToString(level) << "] " << this->_type << " : " << message << "\n";
    else
        std::cout << "[" << logLevelsToString(level) << "] " << this->_type << " : " << message << "\n";
}

void Log::info(const std::string& message)
{
    logMessage(LogLevels::Info, message);
}

void Log::debug(const std::string& message)
{
    logMessage(LogLevels::Debug, message);
}

void Log::warning(const std::string& message)
{
    logMessage(LogLevels::Warning, message);
}

void Log::error(const std::string& message)
{
    logMessage(LogLevels::Error, message);
}
