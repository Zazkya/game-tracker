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
    DbManager();

    /**
     *@brief Destructor
     */
    ~DbManager();

    bool isOpen();
    bool createTable();
    bool addEntry();
    bool entryExists(QString &name);
    bool updateStatus(QString status, QString name);
    bool updateNote(QString note, QString name);
    bool updateGenre(QString genre, QString name);
    bool updateReleased(QString released, QString name);
    bool updateTime(int time, QString name);
    bool updateMetadata(int metadata, QString name);
    bool updateRating(int rating, QString name);
    bool updateSynopsis(QString synopsis, QString name);
    QSqlQuery queryAll();
    QSqlQuery queryPlatform(QString platform, QString status);
    QSqlQuery queryStatus(QString status);
    QSqlQuery queryGenre(QString genre, QString status);
    QSqlDatabase myDb();
    QString nowDate();


private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
