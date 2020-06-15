#ifndef TESTDLG_H
#define TESTDLG_H

#include <QWidget>

class TestDlg : public QWidget
{
    Q_OBJECT
public:
    explicit TestDlg(QWidget *parent = nullptr);

signals:

public slots:
    void CloseWindows();
};

#endif // TESTDLG_H
