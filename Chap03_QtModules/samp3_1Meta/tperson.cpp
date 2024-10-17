#include "tperson.h"

TPerson::TPerson(const QString &aName, QObject *parent)
    : QObject{parent} {
    m_name = aName;
}

TPerson::~TPerson() {
    qDebug() << "a TPerson object was deleted: " << property("name");
}

int TPerson::age() {
    return m_age;
}

void TPerson::setAge(int value) {
    if (value != m_age) {
        m_age = value;
        emit ageChanged(m_age);
    }
}

void TPerson::increaseAge() {
    m_age++;
    emit ageChanged(m_age);
}
