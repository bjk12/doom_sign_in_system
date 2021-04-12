#include "teacher1.h"
#include "ui_teacher1.h"
extern int hehe1;
teacher1::teacher1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacher1)
{
    hehe1=1;
    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~(
                           Qt::WindowContextHelpButtonHint|
                           Qt::WindowMaximizeButtonHint|
                           Qt::WindowMinimizeButtonHint|
                           Qt::WindowCloseButtonHint)
                   );
    ui->setupUi(this);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

teacher1::~teacher1()
{
    delete ui;
}

void teacher1::on_btn_tclose_clicked()
{
    hehe1=0;
    this->close();
}

void teacher1::on_btn_tcreate_clicked()
{
    if(ui->lineEdit->text()=="321930")
    {
        QString location = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        ui->lineEdit->setText("");
        QFile::copy("./111605.xls",location+"\\student_record.xls");
        QFile::remove("./111605.xls");
        QMessageBox::about(this, "登录成功","student_record.xls电子表格已生成，请在电脑桌面接收。");
    }
    else

        QMessageBox::about(this,"登录失败","密码错误，请重试。");
}

void teacher1::on_btn_ttime_clicked()
{
    if(ui->lineEdit->text()=="321930")
    {
        ui->lineEdit->setText("");
        tim1=new time1();
        tim1->setModal(true);
        tim1->show();
    }
    else
        QMessageBox::about(this,"登录失败","密码错误，请重试。");
}

void teacher1::on_btn_tstude_clicked()
{
    if(ui->lineEdit->text()=="321930")
    {
        ui->lineEdit->setText("");
        QProcess::execute("./bjk_10.exe");
    }
    else
        QMessageBox::about(this,"登录失败","密码错误，请重试。");
}

void teacher1::reject()
{
    if(hehe1==0)
    QDialog::reject();//注释此行，禁止界面关闭
}
