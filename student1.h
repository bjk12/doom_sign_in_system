#ifndef STUDENT1_H
#define STUDENT1_H

#include <QDialog>
#include <QCamera>
#include <QCameraImageCapture>
#include <QPixmap>

namespace Ui {
class student1;
}

class student1 : public QDialog
{
    Q_OBJECT

public:
    explicit student1(QWidget *parent = 0);
    ~student1();

private slots:
    void on_btn_tea_clicked();
    void on_btn_check_clicked();
    void displayImage(int, QImage image);
private:
    Ui::student1 *ui;
    QCamera *my_cam;
    QCameraImageCapture *QCameraImg;
    void reject();
};

#endif // STUDENT1_H
