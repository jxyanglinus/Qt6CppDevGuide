#include "dialog.h"

void Dialog::iniUI() {
    //创建 Underline、Italic、Bold 3 个复选框，并水平布局
    chkBoxUnder = new QCheckBox("Underline");
    chkBoxItalic = new QCheckBox("Italic");
    chkBoxBold = new QCheckBox("Bold");
    QHBoxLayout *HLay1 = new QHBoxLayout();
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);
    //创建 Black、Red、Blue 3 个单选按钮，并水平布局
    radioBlack = new QRadioButton("Black");
    radioBlack->setChecked(true);
    radioRed = new QRadioButton("Red");
    radioBlue = new QRadioButton("Blue");
    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(radioBlack);
    HLay2->addWidget(radioRed);
    HLay2->addWidget(radioBlue);
    //创建“确定”“取消”“退出”3 个按钮，并水平布局
    btnOK = new QPushButton("确定");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("退出");
    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);
    //创建文本框，并设置初始字体
    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello world\n 手工创建");
    QFont font = txtEdit->font(); //获取字体
    font.setPointSize(20); //修改字体大小为 20
    txtEdit->setFont(font); //设置字体
    //创建垂直布局，并设置为主布局
    QVBoxLayout *VLay = new QVBoxLayout(this);
    VLay->addLayout(HLay1); //添加字体类型组
    VLay->addLayout(HLay2); //添加文字颜色组
    VLay->addWidget(txtEdit); //添加 txtEdit
    VLay->addLayout(HLay3); //添加按键组
    setLayout(VLay); //设置为窗口的主布局
}

void Dialog::iniSignalSlots() {
    //3 个设置颜色的单选按钮
    connect(radioBlack, &QRadioButton::clicked, this, &Dialog::do_setFontColor);
    connect(radioRed, &QRadioButton::clicked, this, &Dialog::do_setFontColor);
    connect(radioBlue, &QRadioButton::clicked, this, &Dialog::do_setFontColor);
    //3 个设置字体的复选框
    connect(chkBoxUnder, &QCheckBox::clicked, this, &Dialog::do_chkBoxUnder);
    connect(chkBoxItalic, &QCheckBox::clicked, this, &Dialog::do_chkBoxItalic);
    connect(chkBoxBold, &QCheckBox::clicked, this, &Dialog::do_chkBoxBold);
    //3 个按钮与窗口的槽函数关联
    connect(btnOK, &QPushButton::clicked, this, &Dialog::accept);
    connect(btnClose, &QPushButton::clicked, this, &Dialog::close);
    connect(btnCancel, &QPushButton::clicked, this, &Dialog::reject);
}

void Dialog::do_chkBoxUnder(bool checked) {
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxItalic(bool checked) {
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxBold(bool checked) {
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::do_setFontColor() {
    QPalette plet = txtEdit->palette();
    if (radioBlue->isChecked()) {
        plet.setColor(QPalette::Text, Qt::blue);
    } else if (radioRed->isChecked()) {
        plet.setColor(QPalette::Text, Qt::red);
    } else if (radioBlack->isChecked()) {
        plet.setColor(QPalette::Text, Qt::black);
    } else {
        plet.setColor(QPalette::Text, Qt::black);
    }
    txtEdit->setPalette(plet);
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent) {
    iniUI();
    iniSignalSlots();
    setWindowTitle("手工创建 UI");
}

Dialog::~Dialog() {
}

