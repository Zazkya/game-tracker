#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQueryModel"
#include "dbmanager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DbManager db;



    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(db.queryAll());

    ui->tableView->setModel(model);
   // ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{



    if (index.isValid()) {
        qDebug() << index;

    }
}
