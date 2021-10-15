#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "textbook.h"
#include "mount.h"
#include "browser.h"
#include "calendar.h"
#include "getinfo.h"
#include "buttontest.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void ShowMainWidget();

private slots:
    void on_ButtonTest_clicked();

    void on_GetInfo_clicked();

    void on_monutButton_clicked();

    void on_textButton_clicked();

    void on_OpenHtml_clicked();

    void on_calendar_clicked();

private:
    Ui::Widget *ui;
    ButtonTest *ButtonTestWdiget;
    GetInfo *GetInfoWdiget;
    mount *MountWdiget;
    TextBook *TextWdiget;
    Browser *BrowserWdiget;
    Calendar *CalendarWdiget;
};

#endif // WIDGET_H
