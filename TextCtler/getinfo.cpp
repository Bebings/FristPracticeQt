#include "getinfo.h"
#include "ui_getinfo.h"
#include <QDebug>               //调试输出类
#include <QMessageBox>		//消息框类
GetInfo::GetInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GetInfo)
{
    ui->setupUi(this);
    resize(480,360);
    m_pGenderGroup = new QButtonGroup(this);
    m_pGenderGroup->addButton(ui->radioButtonMan,0);
    m_pGenderGroup->addButton(ui->radioButtonWoman,1);

    m_pStatusGroup = new QButtonGroup(this);
    m_pStatusGroup->addButton(ui->radioButtonGreen,0);
    m_pStatusGroup->addButton(ui->radioButtonYellow,1);
    m_pStatusGroup->addButton(ui->radioButtonRed,2);


    connect(m_pGenderGroup,SIGNAL(buttonClicked(int)),this,SLOT(RecvGenderID(int)));
    connect(m_pStatusGroup,SIGNAL(buttonClicked(int)),this,SLOT(RecvStatusID(int)));

    ui->radioButtonMan->setChecked(true);
    ui->radioButtonGreen->setChecked(true);
    ui->Age0_14->setChecked(true);
}

GetInfo::~GetInfo()
{
    delete ui;
}

void GetInfo:: RecvGenderID(int id)//接收性别单选按钮分组信号
{
    switch (id)
    {
        case 0:
            qDebug()<<tr("男");
            break;
        case 1:
            qDebug()<<tr("女");
            break;
        default:
              break;
    }
}
void GetInfo:: RecvStatusID(int id)//接收状态单选按钮分组信号
{
    switch (id)
    {
        case 0:
            qDebug()<<tr("绿码");
            break;
        case 1:
            qDebug()<<tr("黄码");
            break;
        case 2:
            qDebug()<<tr("红码");
            break;
        default:
              break;
    }
}


void GetInfo::on_Age0_14_toggled(bool checked)
{
    if(checked)
    {
        qDebug()<<tr("年龄段：0-14");
    }
    else
    {
        qDebug()<<tr("不是 0-14");
    }
}


void GetInfo::on_Age14_18_toggled(bool checked)
{
    if(checked)
    {
        qDebug()<<tr("年龄段：14-18");
    }
    else
    {
        qDebug()<<tr("不是 14-18");
    }
}


void GetInfo::on_Age18_24_toggled(bool checked)
{
    if(checked)
    {
        qDebug()<<tr("年龄段：18-24");
    }
    else
    {
        qDebug()<<tr("不是 18-24");
    }
}


void GetInfo::on_Age24_35_toggled(bool checked)
{
    if(checked)
    {
        qDebug()<<tr("年龄段：24-35");
    }
    else
    {
        qDebug()<<tr("不是 24-35");
    }
}


void GetInfo::on_pushButton_clicked()
{
    QString strResult;
    int nGenderID = m_pGenderGroup->checkedId();
    switch (nGenderID)
    {
        case 0:
            strResult += tr("性别：男\r\n");
            break;
        case 1:
            strResult += tr("性别：女\r\n");
            break;
        default:
            strResult += tr("性别：未选中\r\n");
            break;
    }

    int nStatusID = m_pStatusGroup->checkedId();
    switch (nStatusID)
    {
        case 0:
            strResult += tr("状态：绿码\r\n");
            break;
        case 1:
            strResult += tr("状态：黄码\r\n");
            break;
        case 2:
            strResult += tr("状态：红码\r\n");
            break;
        default:
            strResult += tr("状态：未选中\r\n");
            break;
    }

    if(ui->Age0_14->isChecked())
    {
        strResult += tr("年龄段：0-14\r\n");
    }
    else if(ui->Age14_18->isChecked())
    {
        strResult += tr("年龄段：14-18\r\n");
    }
    else if(ui->Age18_24->isChecked())
    {
        strResult += tr("年龄段：18-24\r\n");
    }
    else if(ui->Age24_35->isChecked())
    {
        strResult += tr("年龄段：24-35\r\n");
    }else
    {
        strResult += tr("年龄段：未选中\r\n");
    }

    QMessageBox::information(this,tr("全部信息"),strResult);

}



