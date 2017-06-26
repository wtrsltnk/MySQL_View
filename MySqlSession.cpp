#include "MySqlSession.h"
#include <mysql.h>
#include <fmt/format.h>

Log* MySqlSession::_logger = Log::create<MySqlSession>();

MySqlSession::MySqlSession()
{ }

MySqlSession* MySqlSession::Create(const std::string& host, const std::string& database, const std::string& username, const std::string& password)
{
    auto session = new MySqlSession();

    if (mysql_init(&session->_mysql) == nullptr)
    {
        delete session;
        MySqlSession::_logger->error("unable to initialize MYSQL connector/c");
        return nullptr;
    }

    auto result = mysql_real_connect(&session->_mysql, host.c_str(), username.c_str(), password.c_str(), database.c_str(), MYSQL_PORT, nullptr, 0);

    if (result == nullptr)
    {
        delete session;
        MySqlSession::_logger->error(fmt::format("failed to connect to {0} as {1}", host, username));
        return nullptr;
    }

    session->_database = database;
    session->_host = host;
    session->_password = password;
    session->_username = username;

    return session;
}
