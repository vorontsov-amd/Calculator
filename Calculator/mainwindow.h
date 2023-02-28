#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double numFirst = 0;

private slots:
    void digits_numbers();
    void operations();
    void math_operations();
    void on_pushButtonDot_clicked();
    void on_pushButtonClear_clicked();
    void on_pushButtonEqual_clicked();
};
#endif // MAINWINDOW_H
