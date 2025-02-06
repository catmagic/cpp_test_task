#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QTableView>
#include <QItemSelectionModel>
#include<QSqlIndex>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addTelephonePushButton_released();

    void on_changeTelephonPushButton_released();

    void on_removeTelephonPushButton_released();

private:
    Ui::MainWindow *ui;
    QSqlDatabase sdb;
    QSqlTableModel *model;
    QItemSelectionModel* selectionModel;
};
#endif // MAINWINDOW_H
