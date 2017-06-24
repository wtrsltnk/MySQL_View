#ifndef LOG_H
#define LOG_H

#include <typeinfo>
#include <string>

enum class LogLevels
{
    Info,
    Debug,
    Warning,
    Error,
};

class Log
{
    std::string _type;
    Log(const std::string& type);
public:
    template<class T> static Log* create()
    {
        return new Log(typeid(T).name());
    }

public:
    void logMessage(LogLevels level, const std::string& message);
    void info(const std::string& message);
    void debug(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);
};

#endif // LOG_H
