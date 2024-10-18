#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);
    girl = new TPerson("Summer", this);
    girl->setProperty("sex", "Girl");
    girl->setProperty("age", 16);
    girl->setProperty("score", 100);
    connect(girl, SIGNAL(ageChanged(int)), this, SLOT(do_ageChanged(int)));

    boy = new TPerson("Farquhar", this);
    boy->setProperty("sex", "Boy");
    boy->setProperty("age", 17);
    boy->setProperty("score", 90);
    connect(boy, SIGNAL(ageChanged(int)), this, SLOT(do_ageChanged(int)));


    ui->spinBoy->setValue(boy->age());
    ui->spinGirl->setValue(girl->age());
    ui->spinBoy->setProperty("isBoy", true);
    ui->spinGirl->setProperty("isBoy", false);
    connect(ui->spinBoy, SIGNAL(valueChanged(int)), this, SLOT(do_spinChanged(int)));
    connect(ui->spinGirl, SIGNAL(valueChanged(int)), this, SLOT(do_spinChanged(int)));
    connect(boy, SIGNAL(ageChanged(int)), ui->spinBoy, SLOT(setValue(int)));
    connect(girl, SIGNAL(ageChanged(int)), ui->spinGirl, SLOT(setValue(int)));
}

Widget::~Widget() {
    delete ui;
}

void Widget::do_ageChanged(int value) {
    Q_UNUSED(value);
    TPerson *person = qobject_cast<TPerson *>(sender());
    QString hisName = person->property("name").toString();
    QString hisSex = person->property("sex").toString();
    int hisAge = person->property("age").toInt();
    QString info = QString("Name: %1, Sex: %2, Age: %3").arg(hisName).arg(hisSex).arg(hisAge);
    ui->textEdit->appendPlainText(info);
}

void Widget::do_spinChanged(int arg1) {
    QSpinBox *spin = qobject_cast<QSpinBox *>(sender());
    if (spin->property("isBoy").toBool() == true) {
        boy->setAge(arg1);
    } else {
        girl->setAge(arg1);
    }
}


void Widget::on_btnClassInfo_clicked() {
    const QMetaObject *meta = boy->metaObject();
    ui->textEdit->clear();
    ui->textEdit->appendPlainText(QString("Class Name: %1\n").arg(meta->className()));
    ui->textEdit->appendPlainText("Property:");
    for (int i = meta->propertyOffset(); i < meta->propertyCount(); i++) {
        const char *propName = meta->property(i).name();
        QString propValue = boy->property(propName).toString();
        QString str = QString("Property Name: %1, Value: %2").arg(propName).arg(propValue);
        ui->textEdit->appendPlainText(str);
    }
    ui->textEdit->appendPlainText("");
    ui->textEdit->appendPlainText("classInfo");
    for (int i = meta->classInfoOffset(); i < meta->classInfoCount(); i++) {
        QMetaClassInfo classInfo = meta->classInfo(i);
        QString str = QString("Name = %1, Value = %2").arg(classInfo.name()).arg(classInfo.value());
        ui->textEdit->appendPlainText(str);
    }
}


void Widget::on_btnBoyInc_clicked() {
    boy->increaseAge();
}


void Widget::on_btnGirlInc_clicked() {
    girl->increaseAge();
}

