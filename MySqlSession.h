#ifndef MYSQLSESSION_H
#define MYSQLSESSION_H

#include "Log.h"
#include <string>
#include <mysql.h>

class MySqlSession
{
    static class Log* _logger;

    MYSQL _mysql;
    std::string _host;
    std::string _database;
    std::string _username;
    std::string _password;

    MySqlSession();
public:
    static MySqlSession* Create(const std::string& host, const std::string& database, const std::string& username, const std::string& password);
};

#endif // MYSQLSESSION_H
