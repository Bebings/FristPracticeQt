#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <QTimer>   //定时器类
namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

public slots:
    void Recvtime();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Calendar *ui;
    QTimer *m_timer;
};

#endif // CALENDAR_H
