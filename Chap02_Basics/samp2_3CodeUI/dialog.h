#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QRadioButton>
#include <QCheckBox>
#include <QPlainTextEdit>
#include <QObject>
#include <QPushButton>
#include <QLayout>

class Dialog : public QDialog {
    Q_OBJECT
private:
    QCheckBox *chkBoxUnder; //3 个复选框
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;
    QRadioButton *radioBlack; //3 个单选按钮
    QRadioButton *radioRed;
    QRadioButton *radioBlue;
    QPushButton *btnOK; //3 个按钮
    QPushButton *btnCancel;
    QPushButton *btnClose;
    QPlainTextEdit *txtEdit; //文本框
    void iniUI(); //UI 创建与初始化
    void iniSignalSlots(); //初始化信号与槽的连接
private slots:
    void do_chkBoxUnder(bool checked); //Underline 复选框
    void do_chkBoxItalic(bool checked); //Italic 复选框
    void do_chkBoxBold(bool checked); //Bold 复选框
    void do_setFontColor(); //设置文字颜色
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
