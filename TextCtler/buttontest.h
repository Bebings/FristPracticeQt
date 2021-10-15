#ifndef BUTTONTEST_H
#define BUTTONTEST_H

#include <QWidget>

namespace Ui {
class ButtonTest;
}

class ButtonTest : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonTest(QWidget *parent = nullptr);
    ~ButtonTest();
public slots:
    void FoodIsComing();

private slots:
    void on_hungryButton_clicked();

    void on_ConntButton_clicked();

    void on_DisconntButton_clicked();
private:
    Ui::ButtonTest *ui;
};

#endif // BUTTONTEST_H
