#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include "student1.h"
#include "teacher1.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QTimer *Timer1;
    teacher1 *tea1;
    student1 *stu1;
private slots:
    void on_btn_stu_clicked();

    void on_btn_tea_clicked();

    void on_timeout () ; //定时溢出处理槽函数

private:
    Ui::Dialog *ui;
    void reject();
};

#endif // DIALOG_H
