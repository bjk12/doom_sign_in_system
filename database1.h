#ifndef DATABASE1_H
#define DATABASE1_H

#include <QDialog>

namespace Ui {
class database1;
}

class database1 : public QDialog
{
    Q_OBJECT

public:
    explicit database1(QWidget *parent = 0);
    ~database1();

private:
    Ui::database1 *ui;
};

#endif // DATABASE1_H
