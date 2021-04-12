#ifndef TIME1_H
#define TIME1_H

#include <QDialog>

namespace Ui {
class time1;
}

class time1 : public QDialog
{
    Q_OBJECT

public:
    explicit time1(QWidget *parent = 0);
    ~time1();

private slots:
    void on_btn_ok_clicked();

    void on_btn_close_clicked();

private:
    Ui::time1 *ui;
};

#endif // TIME1_H
