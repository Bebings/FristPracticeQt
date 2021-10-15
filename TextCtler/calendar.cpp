#include "calendar.h"
#include "ui_calendar.h"
#include <QDateTime>
Calendar::Calendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("电子钟"));
    m_timer = new QTimer(this);
    m_timer->setSingleShot(false);
    m_timer->setInterval(1*1000);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(Recvtime()));
    m_timer->start();
    on_pushButton_clicked();
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_pushButton_clicked()
{
    QDateTime dt = QDateTime::currentDateTime();
    ui->calendarWidget->setSelectedDate(dt.date());
    ui->calendarWidget->setFocus();
}


void Calendar:: Recvtime()
{
    QDateTime dt = QDateTime::currentDateTime();
    QString strtime = dt.time().toString("HH:mm:ss");
    ui->lcdNumber->display(strtime);
    ui->progressBar->setValue(dt.time().second());
}

