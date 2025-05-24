#ifndef TASK4_H
#define TASK4_H

#include <QDialog>

namespace Ui {
class task4;
}

class task4 : public QDialog
{
    Q_OBJECT

public:
    explicit task4(QWidget *parent = nullptr);
    ~task4();

private slots:
    void on_pushButton_Task4_Cancel_clicked();

private:
    Ui::task4 *ui;
};

#endif // TASK4_H
