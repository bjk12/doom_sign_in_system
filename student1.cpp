#include "student1.h"
#include "ui_student1.h"

extern int a;
extern int hehe;
extern int N;
extern QList<QString> list_stu1;
extern QTextCodec *codec;
student1::student1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student1)
{
    hehe=1;
    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~(
                           Qt::WindowContextHelpButtonHint|
                           Qt::WindowMaximizeButtonHint|
                           Qt::WindowMinimizeButtonHint|
                           Qt::WindowCloseButtonHint)
                   );
    ui->setupUi(this);
    ui->comboBox->clear();
    for(int i=0;i<N;i++)
    {
    ui->comboBox->addItem(list_stu1[2*i]);
    }
    ui->comboBox->setCurrentIndex(0);
    my_cam = new QCamera(this);//添加显示界面
    my_cam->stop();
    my_cam->setCaptureMode(QCamera::CaptureVideo);//设置摄像头捕获模式
    my_cam->start();//启动摄像头
    QCameraImg = new QCameraImageCapture(my_cam);//截取图像
    connect(QCameraImg, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));//触发的信号为捕获一张图片
    QCameraImg->capture();//拍照获取一帧
    const QPixmap *pixmap = ui->label_2->pixmap();
    if(pixmap)
    {
    QString strr1="./img",strr2=".png";
    QString strr3=QString::number(a);
    strr3=strr1+strr3+strr2;
    pixmap->save(strr3);
    a++;
    }
}

student1::~student1()
{
    delete ui;
}

void student1::on_btn_tea_clicked()
{
    hehe=0;
    this->close();
}

void student1::on_btn_check_clicked()
{
    int i=0,flag=0,flag1=0;
    QString m_strDate,m_strTime,m_strDateTime,str13="";
    QDateTime curDateTime=QDateTime::currentDateTime();
    m_strDate=curDateTime.toString("yyyy-MM-dd");         //格式化日期
    m_strTime=curDateTime.toString("hh:mm:ss");         //格式化时间
    m_strDateTime=curDateTime.toString("yyyy-MM-dd hh:mm:ss");   //格式化日期时间
    QString str11="早上好啊小哥哥，欢迎来到教室(＾▽＾)",str12="早上好啊小姐姐，欢迎来到教室╮(￣▽￣)╭ ";
    str11+="\n当前时间："+m_strTime;
    str12+="\n当前时间："+m_strTime;
    for(;i<N;i++)
    {
        if(ui->comboBox->currentText()==list_stu1[i*2])
        {
            QFile file1("./std.txt");
            if (file1.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                while (!file1.atEnd())
                {
                    QString line = codec->toUnicode(file1.readLine()).trimmed();
                    if(line.isEmpty())
                        break;
                    if(i==line.toInt())
                    {
                        flag1=1;
                        break;
                    }
                }
            file1.close();
            }
            if (flag1==1){
                flag1=0;
                QMessageBox::about(this, "温馨提醒", "你已经签过了，请不要重复签到");
                break;
            }
            else if(list_stu1[2*i+1]=="男")
            {
                QMessageBox::about(this, "签到成功", str11);
            }
            else
            {
                QMessageBox::about(this, "签到成功", str12);
            }
            str13=ui->comboBox->currentText()+"\t"+m_strDate+"\t"+m_strTime;
            //记录生成表格
            QFile file2("./std.txt");
            if (file2.open(QIODevice::Append | QIODevice::Text))
            {
                QTextStream txtOutput(&file2);
                txtOutput <<i<<endl;
                file2.close();
            }
            QFile file3("./111605.xls");
            if (file3.open(QIODevice::Append | QIODevice::Text))
            {
                QTextStream txtOutput(&file3);
                txtOutput <<str13<<endl;
                file3.close();
            }
            break;
        }
        else
        {
            flag++;
            if(flag==N)
            {
                QMessageBox::about(this, "查无此人", "签到失败，请重试或联系老师");
                flag=0;
            }
        }
    }
    //摄像头部分
    QCameraImg->capture();//拍照获取一帧
    const QPixmap *pixmap = ui->label_2->pixmap();
    if(pixmap)
    {
    QString strr1="./img",strr2=".png";
    QString strr3=QString::number(a);
    strr3=strr1+strr3+strr2;
    pixmap->save(strr3);
    a++;
    }
}
void student1::reject()
{
    const QPixmap *pixmap = ui->label_2->pixmap();
    if(pixmap)
    {
    QString strr1="./img",strr2=".png";
    QString strr3=QString::number(a);
    strr3=strr1+strr3+strr2;
    pixmap->save(strr3);
    a++;
    }
    delete my_cam;
    delete QCameraImg;
    if(hehe==0)
        QDialog::reject();//注释此行，禁止界面关闭
}
void student1::displayImage(int , QImage image)
{
    ui->label_2->setPixmap(QPixmap::fromImage(image));//将捕获的图片映射到label中
}
