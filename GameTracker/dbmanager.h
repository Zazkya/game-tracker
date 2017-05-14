#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>


/**
 * @brief The DbManager class
 */

class DbManager
{
public:
    /**
     * @brief Constructor
     * Sets up db and opens it
     * @param path - path to db
     *
     */
    DbManager(const QString &path);

    /**
     *@brief Destructor
     */
    ~DbManager();

    bool isOpen();
    bool createTable();
    bool addEntry();
    bool entryExists(QString &name);
    QSqlQuery queryAll();
    QSqlQuery queryPlatform(QString platform, QString status);
    QSqlQuery queryStatus(QString status);
    QSqlQuery queryGenre(QString genre, QString status);
    QSqlDatabase myDb();

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
