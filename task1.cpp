#include "task1.h"
#include "ui_task1.h"
#include <QString>
#include <QMessageBox>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

task1::task1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::task1)
{
    ui->setupUi(this);

    generateRandomVariables();
}

task1::~task1()
{
    delete ui;
}

void task1::on_pushButton_Task1_Cancel_clicked()
{
    this->close();
}

void task1::generateRandomVariables()
{

    std::srand(std::time(0));

    for (int i = 0; i < 10; ++i) {
        a[i] = std::rand() % 101;
    }
    do {
        c = (std::rand() % 201) - 100;
        d = (std::rand() % 201) - 100;
        if (c > d) std::swap(c, d);
    } while (c == d);
    n = std::rand() % 101;

    QString taskText = QString("ЗАДАНИЕ 1\n"
                               "Дана функция f(x) = %1*x^9 + %2*x^8 + %3*x^7 + %4*x^6 + %5*x^5 + "
                               "%6*x^4 + %7*x^3 + %8*x^2 + %9*x + %10\n"
                               "Найти решение f(x) = 0 на отрезке [%11, %12] методом хорд за %13 итераций.\n"
                               "Если данное уравнение невозможно решить методом хорд, введите #")
                           .arg(a[0]).arg(a[1]).arg(a[2]).arg(a[3]).arg(a[4])
                           .arg(a[5]).arg(a[6]).arg(a[7]).arg(a[8]).arg(a[9])
                           .arg(c).arg(d).arg(n);

    ui->label_test1->setText(taskText);
}

double task1::calculateFunction(double x) const {
    return a[0] * pow(x, 9) + a[1] * pow(x, 8) + a[2] * pow(x, 7) + a[3] * pow(x, 6) +
           a[4] * pow(x, 5) + a[5] * pow(x, 4) + a[6] * pow(x, 3) + a[7] * pow(x, 2) + a[8] * x + a[9];
}

double task1::solveByChordMethod(int c, int d, int n) const {
    double left = c;
    double right = d;
    double f_left = calculateFunction(left);
    double f_right = calculateFunction(right);

    if (fabs(f_left - f_right) < 1e-10) {
        return std::numeric_limits<double>::quiet_NaN(); // Деление на ноль
    }

    for (int i = 0; i < n; ++i) {
        double x = (left * f_right - right * f_left) / (f_right - f_left);
        double f_x = calculateFunction(x);

        if (fabs(f_x) < 1e-10) {
            return x;
        }

        if (f_x * f_left < 0) {
            right = x;
            f_right = f_x;
        } else {
            left = x;
            f_left = f_x;
        }
    }

    return (left * f_right - right * f_left) / (f_right - f_left);
}

bool task1::isSolvable() const
{
    double fc = calculateFunction(c);
    double fd = calculateFunction(d);

    return fc * fd < 0;
}

void task1::on_pushButton_Task1_Ok_clicked()
{
    QString userAnswer = ui->lineEdit_Task1->text();
    bool ok;
    double userValue = userAnswer.toDouble(&ok);

    if (!ok && userAnswer != "#") {
        QMessageBox::warning(this, "Ошибка", "Пожалуйства введите корректное число или '#'");
        return;
    }

    if (isSolvable()) {
        correctAnswer = solveByChordMethod(c, d, n);
    } else {
        correctAnswer = std::numeric_limits<double>::quiet_NaN();
    }

    if (userAnswer == "#") {
        //if(ClientAPI::getInstance()->querry_to_server("task1&c&d&n&answer")=="task1#+")
        if (!isSolvable()) {
            QMessageBox::information(this, "Результат", "Верно! Уравнение не может быть решено методом хорд.");
            // обновлять статистику на сервере
        } else {
            QMessageBox::warning(this, "Результат", "Неверно! Уравнение может быть решено методом хорд.");
            // тоже обновлять
        }
    } else {
        if (!isSolvable()) {
            QMessageBox::warning(this, "Результат", "Неверно! Уравнение не может быть решено методом хорд (необходимо ввести '#').");
        } else {
            double tolerance = 0.0001;
            //if(ClientAPI::getInstance()->querry_to_server("task1&userValue&correctAnswer&tolerance")=="task1+")
            if (fabs(userValue - correctAnswer) < tolerance) {
                QMessageBox::information(this, "Результат", "Верно! Ваш ответ совпадает с решением уравнения.");
            } else {
                QMessageBox::warning(this, "Результат", QString("Неверно! Правильный ответ %1").arg(correctAnswer));
            }
        }
    }

}























// if (userAnswer == "#") {
//     if (!isSolvable()) {
//         QMessageBox::information(this, "Результат", "Верно! Уравнение не может быть решено методом хорд.");
//         // обновлять статистику на сервере
//     } else {
//         QMessageBox::warning(this, "Результат", "Неверно! Уравнение может быть решено методом хорд.");
//         // тоже обновлять
//     }
// } else {
//     if (!isSolvable()) {
//         QMessageBox::warning(this, "Результат", "Неверно! Уравнение не может быть решено методом хорд (необходимо ввести '#').");
//     } else {
//         double tolerance = 0.0001;
//         if (fabs(userValue - correctAnswer) < tolerance) {
//             QMessageBox::information(this, "Результат", "Верно! Ваш ответ совпадает с решением уравнения.");
//         } else {
//             QMessageBox::warning(this, "Результат", QString("Неверно! Правильный ответ %1").arg(correctAnswer));
//         }
//     }
// }
