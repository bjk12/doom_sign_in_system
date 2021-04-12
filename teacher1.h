#ifndef TEACHER1_H
#define TEACHER1_H

#include <QDialog>
#include "time1.h"
namespace Ui {
class teacher1;
}

class teacher1 : public QDialog
{
    Q_OBJECT

public:
    explicit teacher1(QWidget *parent = 0);
    ~teacher1();
    time1 *tim1;
private slots:
    void on_btn_tclose_clicked();

    void on_btn_tcreate_clicked();

    void on_btn_ttime_clicked();

    void on_btn_tstude_clicked();

private:
    Ui::teacher1 *ui;
    void reject();
};

#endif // TEACHER1_H
