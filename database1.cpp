#include "database1.h"
#include "ui_database1.h"

database1::database1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::database1)
{
    ui->setupUi(this);
}

database1::~database1()
{
    delete ui;
}
