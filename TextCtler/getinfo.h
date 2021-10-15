#ifndef GETINFO_H
#define GETINFO_H

#include <QWidget>
#include <QButtonGroup> //按钮分组类头文件
namespace Ui {
class GetInfo;
}

class GetInfo : public QWidget
{
    Q_OBJECT

public:
    explicit GetInfo(QWidget *parent = nullptr);
    ~GetInfo();
public slots:
    void RecvGenderID(int id);//接收性别单选按钮分组信号
    void RecvStatusID(int id);//接收状态单选按钮分组信号
private slots:
    void on_pushButton_clicked();

    void on_Age0_14_toggled(bool checked);

    void on_Age14_18_toggled(bool checked);

    void on_Age18_24_toggled(bool checked);

    void on_Age24_35_toggled(bool checked);
private:
    Ui::GetInfo *ui;
    QButtonGroup *m_pGenderGroup;//性别单选按钮分组
    QButtonGroup *m_pStatusGroup;//状态单选按钮分组
};

#endif // GETINFO_H
