#include "dbmanager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>


/**
 * @brief DbManager::DbManager
 * Connects to db
 * @param path
 * path of db
 */
DbManager::DbManager(const QString &path){
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    //TODO: add message for failed connect
}

/**
 * @brief DbManager::~DbManager
 * closes db connection
 */
DbManager::~DbManager(){
    if (m_db.isOpen()){
        m_db.close();
    }
}

/**
 * @brief DbManager::isOpen
 * check if db is open
 * @return
 * return answer
 */
bool DbManager::isOpen(){
    return m_db.isOpen();
}

/**
 * @brief DbManager::createTable
 * create table
 * @return
 * return tru if table is created
 */
bool DbManager::createTable(){
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS gameTable(id INTEGER PRIMARY KEY, name TEXT NOT NULL, platform TEXT NOT NULL, status TEXT NOT NULL, dateAdded TEXT NOT NULL, dateReleased TEXT NOT NULL, dateModified TEXT NOT NULL, eTime INTEGER NOT NULL, genre TEXT NOT NULL, notes CLOB NOT NULL, metadata INTEGER NOT NULL, rating INTEGER NOT NULL, synopsis CLOB NOT NULL);");

    if(!query.exec()){
        success = false;
    }else success = true;

    return success;
}

/**
 * @brief DbManager::addEntry
 * add entry to db
 * @return
 * returns true if successfull
 */
bool DbManager::addEntry(){
    bool success = false;
    //TODO:Add method to add to db. Do after api config

    return success;
}

/**
 * @brief DbManager::entryExists
 * check if entry exists
 * @param name
 * name of entry
 * @return
 * return tru if exists
 */
bool DbManager::entryExists(QString &name){
    bool exists = false;
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM gameTable WHERE name = (:name)");
    checkQuery.bindValue(":name", name);
    if (checkQuery.exec()){
          if (checkQuery.next()){
              exists = true;
          }
      }
    return exists;
}

/**
 * @brief DbManager::queryAll
 * creates query for everything in db
 * @return
 * returns query
 */
QSqlQuery DbManager::queryAll(){
    QSqlQuery query;
    query.prepare("SELECT name, platform, genre, status, dateAdded, dateModified FROM gameTable");
    query.exec();
    return query;
}

/**
 * @brief DbManager::queryPlatform
 * queries platform - used for sorting
 * @return
 * returns query
 */
QSqlQuery DbManager::queryPlatform(QString platform, QString status){
    QSqlQuery query;
    query.prepare("SELECT name, platform, genre, status, dateAdded, dateModified FROM gameTable WHERE status = (:status) AND platform = (:platform)");
    query.bindValue(":status", status);
    query.bindValue(":platform", platform);
    query.exec();
    return query;
}


/**
 * @brief DbManager::queryStatus
 * queries status of game
 * @param status
 * Complete, Incomplete, Retired
 * @return
 * returns query
 */
QSqlQuery DbManager::queryStatus(QString status){
    QSqlQuery query;
    query.prepare("SELECT name, platform, genre, dateAdded, dateModified FROM gameTable WHERE status = (:status) ");
    query.bindValue(":status", status);
    query.exec();
    return query;
}

/**
 * @brief DbManager::queryGenre
 * queries genre of games - used for sorting
 * @return
 * returns query
 */
QSqlQuery DbManager::queryGenre(QString genre, QString status){
    QSqlQuery query;
    query.prepare("SELECT name, platform, genre, status, dateAdded, dateModified FROM gameTable WHERE status = (:status) AND genre = (:genre)");
    query.bindValue(":status", status);
    query.bindValue(":genre", genre);
    query.exec();
    return query;
}

/**
 * @brief DbManager::myDb
 * database obgect - used for QT display
 * @return
 * returns m_db
 */
QSqlDatabase DbManager::myDb(){
    return m_db;
}










