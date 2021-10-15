#include "buttontest.h"
#include "ui_buttontest.h"
#include <QMessageBox>
ButtonTest::ButtonTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonTest)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(FoodIsComing()));
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));
    on_ConntButton_clicked();
}

ButtonTest::~ButtonTest()
{
    delete ui;
}
void ButtonTest::FoodIsComing()
{
  QMessageBox::information(this, tr("送餐"), tr("叮咚！外卖已送达"));
}


void ButtonTest::on_hungryButton_clicked()
{
    QMessageBox::information(this, tr("评价"), tr("好像还不错！"));
}


void ButtonTest::on_ConntButton_clicked()
{
    connect(ui->lineEdit,SIGNAL(textEdited(QString)),ui->label,SLOT(setText(QString)));

    ui->ConntButton->setEnabled(false);
    ui->DisconntButton->setEnabled(true);
}


void ButtonTest::on_DisconntButton_clicked()
{
    disconnect(ui->lineEdit,SIGNAL(textEdited(QString)),ui->label,SLOT(setText(QString)));

    ui->ConntButton->setEnabled(true);
    ui->DisconntButton->setEnabled(false);
}
