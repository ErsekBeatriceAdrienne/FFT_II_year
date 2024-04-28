#include "databaseconnection.h"

DatabaseConnection :: DatabaseConnection(const QString &server,
                                        const QString &driver,
                                        const QString &user,
                                        const QString &password,
                                        const QString database_name,
                                        bool trusted_connection)
{
    msSQL_database = QSqlDatabase :: addDatabase( "QODBC" );

    msSql_server = server;
    msSql_database_name = database_name;
    msSql_password = password;
    msSql_user = user;
    msSql_driver = driver;
    this->trusted_connection = trusted_connection;
}

bool DatabaseConnection :: connect_database( QString *error )
{
    msSQL_database.setDatabaseName(QString("DRIVER={%1};"
                                           "SERVER=%2;"
                                           "DATABASE=%3;"
                                           "UID=%4;"
                                           "PWD=%5;"
                                           "Trusted_Connection=%6;")
                                       .arg(msSql_driver)
                                       .arg(msSql_server)
                                       .arg(msSql_database_name)
                                       .arg(msSql_user)
                                       .arg(msSql_password)
                                       .arg(trusted_connection ? "Yes" : "No"));
    if ( msSQL_database.open() ) {
        if ( error != nullptr ) {
            *error = msSQL_database.lastError().text();
        }
        return false;
    }
    return true;
}
