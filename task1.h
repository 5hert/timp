#ifndef TASK1_H
#define TASK1_H

#include <QDialog>





  // Задача
  // дана функция f(x) = a0*x^9+a1*x^8+...+a7*x^2+ a8*x+a9
  // найти решение f(x) = 0 на отрезке [c,d] методом хорд за n итераций.
  // если методом решить нельзя, ввести #

  // а0,а1,а2,...,а8,а9,с,d,n генерируются рандомно
  // подаётся ответ на сервер, там проверяется на правильность, пока что хотя бы реализовать проверку на клиенте




namespace Ui {
class task1;
}

class task1 : public QDialog
{
    Q_OBJECT
    friend class TestTask1;

public:
    explicit task1(QWidget *parent = nullptr);
    ~task1();
    const int* getA() const { return a; }
    int& getC() { return c; }
    int& getD() { return d; }
    int& getN() { return n; }
    double getCorrectAnswer() const { return correctAnswer; }


private slots:
    void on_pushButton_Task1_Cancel_clicked();
    void on_pushButton_Task1_Ok_clicked();

private:
    Ui::task1 *ui;
    void generateRandomVariables();
    double calculateFunction(double x) const;
    double solveByChordMethod(int c, int d, int n) const;
    bool isSolvable() const;

    int a[10];
    int c;
    int d;
    int n;
    double correctAnswer;
};

#endif // TASK1_H
