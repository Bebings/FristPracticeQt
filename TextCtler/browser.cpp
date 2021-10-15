#include "browser.h"
#include "ui_browser.h"
#include <QDebug>
#include <QFileDialog>
#include <QUrl>
#include <QSettings>    //保存和加载配置的类
Browser::Browser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Browser)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("浏览器"));
    ui->plainTextEdit->setReadOnly(true);
    ui->textBrowser->setOpenExternalLinks(true);
    ui->pushButtonBack->setEnabled(false);
    ui->pushButtonForeward->setEnabled(false);
    connect(ui->pushButtonBack,SIGNAL(clicked()),ui->textBrowser,SLOT(backward()));
    connect(ui->pushButtonForeward,SIGNAL(clicked()),ui->textBrowser,SLOT(foreward()));
    //调用加载配置项的函数
    LoadSettings();

}

Browser::~Browser()
{
    delete ui;
}

void Browser::on_pushButtonOpen_clicked()
{
    QUrl urlFile = QFileDialog::getOpenFileUrl(this,"open HTIML",QUrl(),"HTML files(*.htm *.html)");
    if(!urlFile.isEmpty())
    {
        qDebug()<<urlFile;
        ui->textBrowser->setSource(urlFile);
    }
}


void Browser::on_textBrowser_backwardAvailable(bool arg1)
{
    ui->pushButtonBack->setEnabled(arg1);
}


void Browser::on_textBrowser_forwardAvailable(bool arg1)
{
    ui->pushButtonForeward->setEnabled(arg1);
}


void Browser::on_textBrowser_textChanged()
{
    QString strHtml = ui->textBrowser->toHtml();
    ui->plainTextEdit->setPlainText(strHtml);
}
//关闭之前执行这个虚函数
void Browser::closeEvent(QCloseEvent *)
{
    //保存配置
    SaveSettings();
}
//负责保存配置的函数
void Browser::SaveSettings()
{
    //机构或公司名设为 QtGuide，应用程序名设为 SimpleBrowser
    QSettings settings("QtGuide", "SimpleBrowser");
    //主窗口状态信息
    QByteArray baMainWidget = this->saveGeometry();
    //分裂器状态信息
    QByteArray baSplitter = ui->splitter->saveState();
    //源文件 URL
    QUrl urlSrc = ui->textBrowser->source();

    //保存为配置项，键名自己随便取
    settings.setValue("MainWidget", baMainWidget);
    settings.setValue("Splitter", baSplitter);
    settings.setValue("URL", urlSrc);
    //搞定，settings 对象在栈里面，该对象析构时自动存储所有配置
}
//负责加载配置的函数
void Browser::LoadSettings()
{
    //机构或公司名设为 QtGuide，应用程序名设为 SimpleBrowser
    //settings 的构造函数自己会去读取上次保存的注册表或配置文件信息
    QSettings settings("QtGuide", "SimpleBrowser");

    //判断键名是否存在，然后取出各个键名对应的键值，还原以前保存的状态
    //主窗口
    if(settings.contains("MainWidget"))
    {
        QByteArray baMainWidget = settings.value("MainWidget").toByteArray();
        this->restoreGeometry(baMainWidget);
    }
    //分裂器
    if(settings.contains("Splitter"))
    {
        QByteArray baSplitter = settings.value("Splitter").toByteArray();
        ui->splitter->restoreState(baSplitter);
    }
    //源文件URL
    if(settings.contains("URL"))
    {
        QUrl urlSrc = settings.value("URL").toUrl();
        ui->textBrowser->setSource(urlSrc);
    }
}
