#include "time1.h"
#include "ui_time1.h"

time1::time1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::time1)
{
    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~(
                           Qt::WindowContextHelpButtonHint|
                           Qt::WindowMaximizeButtonHint|
                           Qt::WindowMinimizeButtonHint|
                           Qt::WindowCloseButtonHint)
                   );
    ui->setupUi(this);
}

time1::~time1()
{
    delete ui;
}

void time1::on_btn_ok_clicked()
{
    int a1=ui->lineEdit->text().toInt();
    int a2=ui->lineEdit_2->text().toInt();
    if(a1>=0 && a1<24 && a2>=0 && a2<60 )
    {
        QFile file1("./time.txt");
        file1.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream txtOutput(&file1);
        txtOutput <<a1<< endl;
        txtOutput <<a2<< endl;
        file1.close();
        QMessageBox::about(this,"成功修改","签到截止时间已被修改，次日生效。");
    }
    else
        QMessageBox::about(this,"时间错误","请按规定格式输入时间（时：[0,24)，分:[0,60)）。");
}

void time1::on_btn_close_clicked()
{
    this->close();
}
