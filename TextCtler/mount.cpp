#include "mount.h"
#include "ui_mount.h"
#include <QDebug>
#include <QMessageBox>
#include <QCryptographicHash>
mount::mount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mount)
{
    ui->setupUi(this);
     ui->Password->setEchoMode(QLineEdit::Password);
     this->setWindowTitle(tr("登录"));
}

mount::~mount()
{
    delete ui;
}

void mount::on_Mount_clicked()
{
    if(ui->UserName->text().isEmpty()||ui->Password->text().isEmpty())
    {
        QMessageBox::warning(this,tr("警告"),tr("用户名或密码为空，请重新输入！"));
        return;
    }
    m_UserName = ui->UserName->text();
    m_Password = QCryptographicHash::hash(ui->Password->text().toUtf8(),QCryptographicHash::Sha3_256);
    QString strMsg = tr("用户名：") + m_UserName + tr("\r\n") + tr("密码 Hash：");
    //把每个 Hash 字节转成一对十六进制字符显示
    // 256 bit 对应 32 字节，变成 64 个十六进制字符打印
    strMsg += m_Password.toHex();
    //打印消息
    qDebug()<<strMsg;
    //弹窗显示，注意：实际应用中会将用户名和密码 Hash 与数据库或配置文件里的做比较，而不是弹窗
    QMessageBox::information(this, tr("用户信息"), strMsg);

}


void mount::on_Quit_clicked()
{
    this->close();
}

