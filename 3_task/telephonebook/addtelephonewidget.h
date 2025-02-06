#ifndef ADDTELEPHONEWIDGET_H
#define ADDTELEPHONEWIDGET_H

#include <QDialog>

namespace Ui {
class addTelephoneWidget;
}

class addTelephoneWidget : public QDialog
{
    Q_OBJECT

public:
    explicit addTelephoneWidget(QWidget *parent = nullptr);
    QString GetFullName()const;
    QString GetTelephoneNumber()const;

    ~addTelephoneWidget();

private:
    Ui::addTelephoneWidget *ui;
};

#endif // ADDTELEPHONEWIDGET_H
