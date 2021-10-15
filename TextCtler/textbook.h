#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include <QWidget>
#include <QTextCharFormat>  //文本格式类

namespace Ui {
class TextBook;
}

class TextBook : public QWidget
{
    Q_OBJECT

signals:    //添加自定义的信号
    void SendMsg();  //信号只需要声明，不要给信号写实体代码

public:
    explicit TextBook(QWidget *parent = nullptr);
    ~TextBook();

private slots:


    void on_Weight_clicked(bool checked);

    void on_Italic_clicked(bool checked);

    void on_underLine_clicked(bool checked);

    void on_FortGroundColor_clicked();

    void on_BackGroundColor_clicked();
    void on_lineEdit_editingFinished();

    void on_textEdit_currentCharFormatChanged(const QTextCharFormat &format);

    void on_textEdit_textChanged();

private:
    Ui::TextBook *ui;
};


#endif // TEXTBOOK_H
