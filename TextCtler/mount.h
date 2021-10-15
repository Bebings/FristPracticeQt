#ifndef MOUNT_H
#define MOUNT_H

#include <QWidget>

namespace Ui {
class mount;
}

class mount : public QWidget
{
    Q_OBJECT

public:
    explicit mount(QWidget *parent = nullptr);
    ~mount();

private slots:
    void on_Mount_clicked();

    void on_Quit_clicked();

private:
    Ui::mount *ui;

    QString m_UserName;
    QByteArray m_Password;
};

#endif // MOUNT_H
