#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号函数，信号函数是没有返回值的
    //返回值是void，并且函数不需要再cpp中实现
    //信号函数是可以带参数的
    void SayHello();
    void SayHello(QString toSomeBody);

};

#endif // TEACHER_H
