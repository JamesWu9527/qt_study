#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::RequestTeacher()
{
    qDebug()<<"我收到老师SayHello函数了";
}

void Student::RequestTeacher(QString toSomebody)
{
    qDebug()<<"我收到老师SayHello函数了"<<"to"<<toSomebody.toUtf8().data();
}
