#ifndef CHANGETELEPHONEWIDGET_H
#define CHANGETELEPHONEWIDGET_H

#include <QDialog>

namespace Ui {
class ChangeTelephoneWidget;
}

class ChangeTelephoneWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeTelephoneWidget(QWidget *parent = nullptr);
    QString GetFullName()const;
    QString GetTelephoneNumber()const;
    void SetFullName(QString);
    void SetTelephoneNumber(QString);

    ~ChangeTelephoneWidget();


private:
    Ui::ChangeTelephoneWidget *ui;
};

#endif // CHANGETELEPHONEWIDGET_H
