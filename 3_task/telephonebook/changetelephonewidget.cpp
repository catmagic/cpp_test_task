#include "changetelephonewidget.h"
#include "ui_changetelephonewidget.h"

ChangeTelephoneWidget::ChangeTelephoneWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangeTelephoneWidget)
{
    ui->setupUi(this);
}

ChangeTelephoneWidget::~ChangeTelephoneWidget()
{
    delete ui;
}

QString ChangeTelephoneWidget::GetFullName()const
{
    return ui->fullNameLineEdit->text();
}
QString ChangeTelephoneWidget::GetTelephoneNumber()const
{
    return ui->telephoneNumberLineEdit->text();
}
void ChangeTelephoneWidget::SetFullName(QString str)
{
    ui->fullNameLineEdit->setText(str);
}
void ChangeTelephoneWidget::SetTelephoneNumber(QString str)
{
    ui->telephoneNumberLineEdit->setText(str);
}
