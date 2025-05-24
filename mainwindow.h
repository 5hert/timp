#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    task1 *task1_ui;
    task2 *task2_ui;
    task3 *task3_ui;
    task4 *task4_ui;

public slots:
    void slot_show(QString);
private slots:
    void on_pushButton_Exit_clicked();
    void on_pushButton_Task1_clicked();
    void on_pushButton_Task2_clicked();
    void on_pushButton_Task3_clicked();
    void on_pushButton_Task4_clicked();
};

#endif // MAINWINDOW_H
