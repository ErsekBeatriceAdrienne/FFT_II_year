#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

class DatabaseConnection
{

public:
    DatabaseConnection(const QString &server,
                       const QString &driver,
                       const QString &user,
                       const QString &password,
                       const QString database_name,
                       bool trusted_connection = true);

    bool connect_database( QString *error = nullptr);

private:
    QString msSql_server,
            msSql_driver,
            msSql_user,
            msSql_password,
            msSql_database_name;

    QSqlDatabase msSQL_database;

    bool trusted_connection;
};

#endif // DATABASECONNECTION_H
