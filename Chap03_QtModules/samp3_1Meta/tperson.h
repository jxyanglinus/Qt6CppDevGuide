#ifndef TPERSON_H
#define TPERSON_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QMetaClassInfo>

class TPerson : public QObject {
    Q_OBJECT
    Q_CLASSINFO("Author", "Yang")
    Q_CLASSINFO("School", "TL")
    Q_CLASSINFO("Version", "114.514")
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)
private:
    int m_age = 13;
    int m_score = 399;
    QString m_name = "";
public:
    explicit TPerson(const QString &aName, QObject *parent = nullptr);
    ~TPerson();
    int age();
    void setAge(int value);
    void increaseAge();
signals:
    void ageChanged(int value);
};

#endif // TPERSON_H
