#include "mywidget.h"

#include <QApplication> //包含一个应用程序类的应用

int main(int argc, char *argv[])
{
    //应用程序对象，在QT中有且仅有一个
    QApplication a(argc, argv);

    myWidget w;
    w.show();

    //让应用a进入消息循环
    return a.exec();
}
