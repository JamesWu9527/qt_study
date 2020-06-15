#ifndef MYQPUSHBUTTON_H
#define MYQPUSHBUTTON_H

#include <QPushButton>

class myQpushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myQpushButton(QWidget *parent = nullptr);

    ~myQpushButton();
signals:

};

#endif // MYQPUSHBUTTON_H
