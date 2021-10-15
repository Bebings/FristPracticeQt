#ifndef BROWSER_H
#define BROWSER_H

#include <QWidget>

namespace Ui {
class Browser;
}

class Browser : public QWidget
{
    Q_OBJECT

public:
    explicit Browser(QWidget *parent = nullptr);
    ~Browser();

private slots:
    void on_pushButtonOpen_clicked();

    void on_textBrowser_backwardAvailable(bool arg1);

    void on_textBrowser_forwardAvailable(bool arg1);

    void on_textBrowser_textChanged();

private:
    Ui::Browser *ui;
    //保存配置
    void SaveSettings();
    //加载配置
    void LoadSettings();

protected:
    virtual void closeEvent(QCloseEvent *);
};

#endif // BROWSER_H
