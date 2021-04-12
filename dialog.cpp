#include "dialog.h"
#include "ui_dialog.h"

QList<QString> list_stu1;
QList<int> list_data;
QTextCodec *codec = QTextCodec::codecForName("GBK");
int N=0,fin=0,flag2=0,a=0;//flag2标志位0代表未截止，3代表已截止
int flag3=0;//flag3标志位2代表表格已生成，5代表篡改时间已处理，6代表篡改时间未处理
int hehe=10,hehe1=10,hh=0,mm=0;
quint32 flag1=0,clik=0;//flag1标志位1代表关闭使能。
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    for(int i=0;i<6;i++)
    {
        list_data.append(0);
    }
    QFile file1("./std.txt");
    if (file1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        file1.close();
    }
    else
    {
        file1.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream txtOutput(&file1);
        txtOutput <<-1<< endl;
        file1.close();
    }
    QFile file2("./csc.txt");
    if (file2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        file2.close();
    }
    else
    {
        file2.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream txtOutput(&file2);
        txtOutput <<25<< endl;
        txtOutput <<25<< endl;
        txtOutput <<25<< endl;
        file2.close();
    }
    QFile file3("./program.txt");
    if (file3.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        file3.close();
    }
    else
    {
        file3.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream txtOutput(&file3);
        txtOutput <<2019<< endl;
        txtOutput <<1<< endl;
        txtOutput <<1<< endl;
        txtOutput <<1<< endl;
        txtOutput <<1<< endl;
        txtOutput <<1<< endl;
        file3.close();
    }
    QFile file4("./time.txt");
    if (file4.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        file4.close();
    }
    else
    {
        file4.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream txtOutput(&file4);
        txtOutput <<0<< endl;
        txtOutput <<0<< endl;
        file4.close();
    }
    QFile file5("./test.txt");
    if (file5.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        int i=0;
        while (!file5.atEnd())
        {
            QString line = codec->toUnicode(file5.readLine()).trimmed();
            if(line.isEmpty())
                break;
            i++;
            list_stu1.append(line.section(" ",0,0));
            list_stu1.append(line.section(" ",1,1));
        }
        N=i;
        file5.close();
    }
    else
    {
        file5.open(QIODevice::WriteOnly | QIODevice::Text);
        file5.close();
    }
    QFile file6("./time.txt");
    if (file6.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        int i=0;
        while (!file6.atEnd())
        {
            QString line = codec->toUnicode(file6.readLine()).trimmed();
            if(line.isEmpty())
                break;
            if(i==0)
                hh=line.toInt();
            else
                mm=line.toInt();
            i++;
        }
        file6.close();
    }
    Timer1=new QTimer(this);
    Timer1->stop();
    Timer1->setInterval (250) ;
    connect(Timer1,SIGNAL(timeout()),this,SLOT(on_timeout()));
    Timer1->start () ;
    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~(
                           Qt::WindowContextHelpButtonHint|
                           Qt::WindowMaximizeButtonHint|
                           Qt::WindowMinimizeButtonHint|
                           Qt::WindowCloseButtonHint)
                   );
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn_stu_clicked()
{
    stu1=new student1();
    stu1->setModal(true);
    stu1->show();
}

void Dialog::on_btn_tea_clicked()
{
    tea1=new teacher1();
    tea1->setModal(true);
    tea1->show();
}

void Dialog::on_timeout()
{
    Timer1->stop();
    clik++;
    if(clik>400000)
        clik=100;
    QString str14="有人在\t",str15,str16="\t——\t——\t未及时签到",str17="\t修改过时间";
    QFile file1("./program.txt");
    if (file1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        int i=0;
        while (!file1.atEnd())
        {
            QString line = codec->toUnicode(file1.readLine()).trimmed();
            if(line.isEmpty())
                break;
            list_data[i]=line.toInt();
            i++;
        }
        file1.close();
    }
    QTime T1=QTime::currentTime();
    QDate D1=QDate::currentDate();
    if((D1.year()-2000)*400+D1.month()*40+D1.day()>400*(list_data[0]-2000)+40*list_data[1]+list_data[2])
    {
        QFile file2("./program.txt");
        file2.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream txtOutput(&file2);
        txtOutput <<D1.year()<< endl;
        txtOutput <<D1.month()<< endl;
        txtOutput <<D1.day()<< endl;
        txtOutput <<T1.hour()<< endl;
        txtOutput <<T1.minute()<< endl;
        txtOutput <<T1.second()<< endl;
        file2.close();
    }
    else if((D1.year()-2000)*400+D1.month()*40+D1.day()==400*(list_data[0]-2000)+40*list_data[1]+list_data[2])
            if((3600*(T1.hour())+60*(T1.minute())+T1.second()) >= list_data[3]*3600+list_data[4]*60+list_data[5])
            {
                QFile file3("./program.txt");
                file3.open(QIODevice::WriteOnly | QIODevice::Text);
                QTextStream txtOutput(&file3);
                txtOutput <<D1.year()<< endl;
                txtOutput <<D1.month()<< endl;
                txtOutput <<D1.day()<< endl;
                txtOutput <<T1.hour()<< endl;
                txtOutput <<T1.minute()<< endl;
                txtOutput <<T1.second()<< endl;
                file3.close();
            }
            else flag3=6;
        else flag3=6;
    if(flag3==6){
        flag3=5;
        QFile file4("./csc.txt");
        file4.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream txtOutput(&file4);
        txtOutput <<list_data[3]<< endl;
        txtOutput <<list_data[4]<< endl;
        txtOutput <<list_data[5]<< endl;
        file4.close();
    }
    if((3600*(T1.hour())+60*(T1.minute())+T1.second())>=hh*3600+mm*60 && clik>30 && fin==0
            && (3600*(T1.hour())+60*(T1.minute())+T1.second())<=hh*3600+mm*60+5)
    {
        fin++;
        if(hehe==1)
        {
            hehe=0;
            stu1->close();
        }
        int flag4=0;//标志位1，今天有签到
        for(int i=0;i<N;i++)
        {
            QFile file5("./std.txt");
            if (file5.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                while (!file5.atEnd())
                {
                    QString line = codec->toUnicode(file5.readLine()).trimmed();
                    if(line.isEmpty())
                        break;
                    if(i==line.toInt())
                    {
                        flag4=1;
                        break;
                    }
                }
                file5.close();
            }
            if(flag4==0)
            {
                str15=list_stu1[2*i];
                QFile file6("./111605.xls");
                if (file6.open(QIODevice::Append | QIODevice::Text))
                {
                    QTextStream txtOutput(&file6);
                    txtOutput <<str15<<str16<< endl;
                    file6.close();
                }
                str15="";
            }
            else
                flag4=0;
        }
        QFile file7("./std.txt");
        if (file7.open(QIODevice::WriteOnly | QIODevice::Text))
        {
        QTextStream txtOutput(&file7);
        txtOutput <<-1<< endl;
        file7.close();
        }
        QFile file8("./program.txt");
        if (file8.open(QIODevice::WriteOnly | QIODevice::Text))
        {
        QTextStream txtOutput(&file8);
        txtOutput <<2019<< endl;
        txtOutput <<1<< endl;
        txtOutput <<1<< endl;
        txtOutput <<1<< endl;
        txtOutput <<1<< endl;
        txtOutput <<1<< endl;
        file8.close();
        }
        QFile file9("./csc.txt");
        if (file9.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            int i=3;
            while (!file9.atEnd())
            {
                QString line = codec->toUnicode(file9.readLine()).trimmed();
                if(line.isEmpty())
                    break;
                list_data[i]=line.toInt();
                i++;
            }
            file9.close();
        }
        QFile file10("./csc.txt");
        if (file10.open(QIODevice::WriteOnly | QIODevice::Text))
        {
        QTextStream txtOutput(&file10);
        txtOutput <<25<< endl;
        txtOutput <<25<< endl;
        txtOutput <<25<< endl;
        file10.close();
        }
        if(list_data[3]!=25)
        {
            QFile file11("./111605.xls");
            if (file11.open(QIODevice::Append | QIODevice::Text))
            {
                QTextStream txtOutput(&file11);
                txtOutput <<str14;
                txtOutput <<list_data[3]<<":"<<list_data[4]<<":"<<list_data[5];
                txtOutput <<str17<<endl;
                file11.close();
            }
        }
        flag3=2;
        flag1=1;
        this->close();
    }
    else if((3600*(T1.hour())+60*(T1.minute())+T1.second())>hh*3600+mm*60 )
    {
        flag2=3;
        QMessageBox::about(this, "你迟到了", "没关系，明天记得早来呦 (￣.￣)。");
        tea1=new teacher1();
        tea1->setModal(true);
        tea1->show();
        if(hehe==1)
        {
            hehe=0;
            stu1->close();
        }
        flag1=1;
        this->close();
    }
    else
        Timer1->start () ;
}

void Dialog::reject()
{
    if(flag1==1)
        QDialog::reject();
}
