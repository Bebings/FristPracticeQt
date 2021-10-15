#include "textbook.h"
#include "ui_textbook.h"
#include <QDebug>
#include <QIntValidator>    //整数验证器
#include <QFont>            //综合字体格式
#include <QColorDialog>     //用于选取前景色和背景色
#include <QBrush>           //颜色画刷

TextBook::TextBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextBook)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("文本编辑"));
    ui->Weight->setCheckable(true);
    ui->Italic->setCheckable(true);
    ui->underLine->setCheckable(true);
    QIntValidator *vali = new QIntValidator(0,72);
    ui->fontComboBox->setValidator(vali);
    ui->lineEdit->setText(QString("").setNum(9));
    connect(ui->fontComboBox, SIGNAL(currentIndexChanged(QString)),
            ui->textEdit, SLOT(setFontFamily(QString)));
    //丰富文本编辑框初始内容
    ui->textEdit->setHtml("<b>粗体字的行<br></b>"
                          "<i>斜体字的行<br></i>"
                          "<u>下划线的行<br></u>"
                          "<font style=\"color:red;\">文本前景色<br></font>"
                          "<font style=\"background:yellow;\">文字背景色<br></font>"
                          "<font style=\"font-size:18pt;\">字号大小变化的行<br></font>"
                          "<font style=\"font-family:黑体;\">字体家族变化的行<br></font>"
                          );
}

TextBook::~TextBook()
{
    delete ui;
}



void TextBook::on_Weight_clicked(bool checked)//加粗
{
    if(checked)
    {
        ui->textEdit->setFontWeight(QFont::Bold);   //粗体
    }
    else
    {
        ui->textEdit->setFontWeight(QFont::Normal); //普通
    }
}


void TextBook::on_Italic_clicked(bool checked) //斜体
{
    ui->textEdit->setFontItalic(checked);
}


void TextBook::on_underLine_clicked(bool checked)//下划线
{
    ui->textEdit->setFontUnderline(checked);
}

void TextBook::on_FortGroundColor_clicked()
{
    QColor clr = QColorDialog::getColor(Qt::black); //默认是黑色文字
    if(clr.isValid())   //如果用户选了颜色
    {
        ui->textEdit->setTextColor(clr);
        //同步设置该按钮的前景色
        QString strSS = tr("color: %1").arg(clr.name());
        ui->FortGroundColor->setStyleSheet(strSS);
    }
}
void TextBook::on_BackGroundColor_clicked()
{
    QColor bgclr = QColorDialog::getColor(Qt::white); //用白色背景
    if(bgclr.isValid()) //如果用户选了颜色
    {
        ui->textEdit->setTextBackgroundColor(bgclr);
        //同步设置该按钮的背景色
        QString strSSBG = tr("background: %1").arg(bgclr.name());
        ui->BackGroundColor->setStyleSheet(strSSBG);
    }
}

void TextBook::on_lineEdit_editingFinished()
{
    int nFontSize = ui->lineEdit->text().toInt();
    //设置字号
    ui->textEdit->setFontPointSize( nFontSize );
}


void TextBook::on_textEdit_currentCharFormatChanged(const QTextCharFormat &format)
{
    //粗体检测
    if(format.fontWeight() == QFont::Bold)
    {
        ui->Weight->setChecked(true);
    }
    else
    {
        ui->Weight->setChecked(false);
    }
    //斜体检测
    ui->Italic->setChecked( format.fontItalic() );
    //下划线检测
    ui->underLine->setChecked( format.fontUnderline() );

    //文字前景色画刷，不一定有
    QBrush brushText = format.foreground();
    if( brushText != Qt::NoBrush )//有前景色画刷
    {
        QColor clrText = brushText.color();
        QString strSS = tr("color: %1").arg( clrText.name() );
        ui->FortGroundColor->setStyleSheet( strSS );
    }
    else//没有前景色画刷 Qt::NoBrush
    {
        ui->FortGroundColor->setStyleSheet("");
    }
    //文字背景画刷，不一定有
    QBrush brushBG = format.background();
    if( brushBG != Qt::NoBrush )//有背景色画刷
    {
        QColor clrBG = brushBG.color();
        QString strSSBG = tr("background: %1").arg(clrBG.name());
        ui->BackGroundColor->setStyleSheet(strSSBG);
    }
    else//没背景画刷 Qt::NoBrush
    {
        ui->BackGroundColor->setStyleSheet("");
    }

    //对于字号和字体家族检测，一定要用 QFont 的函数，不要用 QTextCharFormat 的函数
    //QTextCharFormat 的字号和字体家族函数不准，经常为 0 或空串
    QFont curFont = format.font();      //获取 QFont 成员
    int nFontSize = curFont.pointSize();//字号检测
    //如果是 px 形式， QFont::​pointSize() 函数返回 -1
    if( -1 == nFontSize ) //如果 pt 是 -1，是 px 格式
    {
        //如果是 px ，换算成 pt
        nFontSize = (int)( curFont.pixelSize() * 9.0 / 12.0 ) ;
    }
    ui->lineEdit->setText( QString("").setNum(nFontSize) );

    //字体家族检测
    QString strFontFamily = curFont.family();
    ui->fontComboBox->setCurrentText( strFontFamily );
}


void TextBook::on_textEdit_textChanged()
{
    qDebug()<<ui->textEdit->toHtml()<<endl;   //打印丰富文本
}

