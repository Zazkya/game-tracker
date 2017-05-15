#include "mainwindow.h"
#include <QApplication>
#include <dbmanager.h>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    DbManager db;
//    db.createTable();
//    qDebug()<<db.nowDate();
    return a.exec();
}
