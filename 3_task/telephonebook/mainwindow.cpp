#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./addtelephonewidget.h"
#include "./changetelephonewidget.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("TelephoneNumber.sqlite");
    if (!sdb.open()) {
        std::cerr << "Что-то не так с соединением!";

    }

    QSqlQuery a_query;
    // DDL query
    QString str = "CREATE TABLE my_table ("
                  "number integer PRIMARY KEY NOT NULL, "
                  "full_name VARCHAR(255), "
                  "telephone_number VARCHAR(255)"
                  ");";
    bool b = a_query.exec(str);

    model = new QSqlTableModel;
    model->setTable("my_table");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);



    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection	);
    ui->tableView->setModel(model);

    if(model->rowCount()==0)
    {
        ui->changeTelephonPushButton->setEnabled(false);
        ui->removeTelephonPushButton->setEnabled(false);
    }
    else
    {
        ui->tableView->setCurrentIndex(model->index(0,0));
    }


    //ui->tableView->show();
    //ui->tableView->hideColumn(0); // don't show the ID

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addTelephonePushButton_released()
{
    addTelephoneWidget* telephoneWidget=new addTelephoneWidget(this);
    if(telephoneWidget->exec()==QDialog::Accepted)
    {
        QSqlQuery a_query;
        QString str_insert = "INSERT INTO my_table(full_name, telephone_number) "
                             "VALUES ('%1', '%2');";
        QString  str = str_insert.arg(telephoneWidget->GetFullName())
                  .arg(telephoneWidget->GetTelephoneNumber())
                  ;
        str_insert = "UPDATE my_table(full_name, telephone_number) WHERE id"
                    "VALUES ('%1', '%2',%3);";
        a_query.exec(str);
        str = str_insert.arg("1")
                  .arg("2").arg(1)
            ;
        a_query.exec(str);
        model->select();
        ui->tableView->setCurrentIndex(model->index(model->rowCount()-1,0));
        ui->changeTelephonPushButton->setEnabled(true);
        ui->removeTelephonPushButton->setEnabled(true);
    }
    //ui->tableView->setModel()
}


void MainWindow::on_changeTelephonPushButton_released()
{
    ChangeTelephoneWidget* telephoneWidget=new ChangeTelephoneWidget(this);
    int row=ui->tableView->currentIndex().row();
    telephoneWidget->SetFullName(model->data(model->index(row,1)).toString());
    telephoneWidget->SetTelephoneNumber(model->data(model->index(row,2)).toString());
    if(telephoneWidget->exec()==QDialog::Accepted)
    {

        QSqlQuery query;
        query.prepare("UPDATE my_table SET full_name=:name, telephone_number=:phone WHERE number=:id");
        query.bindValue(":id", model->data(model->index(row,0)));
        query.bindValue(":name", telephoneWidget->GetFullName());
        query.bindValue(":phone", telephoneWidget->GetTelephoneNumber());
        query.exec();
        model->select();
        ui->tableView->setCurrentIndex(model->index(row,0));
    }
}


void MainWindow::on_removeTelephonPushButton_released()
{
    int row=ui->tableView->currentIndex().row();
    QSqlQuery query;
    query.prepare("DELETE FROM my_table  WHERE number=:id");
    query.bindValue(":id", model->data(model->index(row,0)));
    query.exec();
    model->select();
    ui->tableView->setCurrentIndex(model->index(std::min(row,model->rowCount()-1),0));
    if(model->rowCount()==0)
    {

        ui->changeTelephonPushButton->setEnabled(false);
        ui->removeTelephonPushButton->setEnabled(false);
    }
}

