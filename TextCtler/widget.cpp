#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include "mount.h"
#include "textbook.h"
#include "calendar.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("功能"));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::ShowMainWidget()
{
    QString strMsg = tr("接收到关闭消息！");
    qDebug()<<strMsg;
    this->show();
}

void Widget::on_ButtonTest_clicked()
{
    ButtonTestWdiget = new ButtonTest();
    ButtonTestWdiget->show();
}


void Widget::on_GetInfo_clicked()
{
    GetInfoWdiget = new GetInfo();
    GetInfoWdiget->show();
}


void Widget::on_monutButton_clicked()
{
    MountWdiget = new mount();
    MountWdiget->show();
}


void Widget::on_textButton_clicked()
{
    TextWdiget = new TextBook();
    TextWdiget->show();
}


void Widget::on_OpenHtml_clicked()
{
    BrowserWdiget = new Browser();
    BrowserWdiget->show();
}


void Widget::on_calendar_clicked()
{
    CalendarWdiget = new Calendar();
    CalendarWdiget->show();
}

