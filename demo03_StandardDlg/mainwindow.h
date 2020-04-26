#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWizard>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QErrorMessage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_ColorDlg_clicked();

    void on_btn_FileDlg_clicked();

    void on_btn_FontDlg_clicked();

    void on_btn_InputDlg_clicked();

    void on_btn_MessageDlg_clicked();

    void on_btn_ProgressDlg_clicked();

    void on_btn_CriticalDlg_clicked();

    void on_btn_GuidDlg_clicked();

private:
    Ui::MainWindow *ui;
    QErrorMessage *m_err;
    QWizardPage *page01();
    QWizardPage *page02();
    QWizardPage *page03();
};
#endif // MAINWINDOW_H
