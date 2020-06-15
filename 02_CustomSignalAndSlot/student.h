#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //需要声明 也需要实现 返回值为void
    void RequestTeacher();
    void RequestTeacher(QString toSomebody);

};

#endif // STUDENT_H
