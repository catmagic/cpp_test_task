#include "addtelephonewidget.h"
#include "ui_addtelephonewidget.h"

addTelephoneWidget::addTelephoneWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addTelephoneWidget)
{
    ui->setupUi(this);
}

addTelephoneWidget::~addTelephoneWidget()
{
    delete ui;
}
QString addTelephoneWidget::GetFullName()const
{
    return ui->fullNameLineEdit->text();
}
QString addTelephoneWidget::GetTelephoneNumber()const
{
    return ui->telephoneNumberLineEdit->text();
}
