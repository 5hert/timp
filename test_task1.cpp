#include <QtTest>
#include <QtMath>
#include "../Client/task1.h"

class TestTask1 : public QObject {
    Q_OBJECT

private slots:
    void testRandomGeneration();
    void testCalculateFunction();
    void testIsSolvable();
    void testChordMethod();


private:
    void modifyCoefficient(task1& dialog, int index, int value);
};

void TestTask1::modifyCoefficient(task1& dialog, int index, int value) {
    int* mutableA = const_cast<int*>(dialog.getA());
    mutableA[index] = value;
}

void TestTask1::testRandomGeneration() { // Тест генерации переменных
    task1 dialog;

    // Проверка коэффициентов
    const int* a = dialog.getA();
    for (int i = 0; i < 10; ++i) {
        QVERIFY(a[i] >= 0 && a[i] <= 100);
    }

    // Проверка интервала [c, d]
    QVERIFY(dialog.getC() < dialog.getD());
    QVERIFY(dialog.getC() >= -100 && dialog.getD() <= 100);

    // Проверка числа итераций
    QVERIFY(dialog.getN() >= 0 && dialog.getN() <= 100);
}

void TestTask1::testCalculateFunction() {
    task1 dialog;

    // Тест 1: f(x) = 5 (все коэффициенты, кроме a9, равны 0)
    modifyCoefficient(dialog, 9, 5);
    for (int i = 0; i < 9; ++i) {
        modifyCoefficient(dialog, i, 0);
    }
    QCOMPARE(dialog.calculateFunction(0), 5.0); // f(0) = 5
    QCOMPARE(dialog.calculateFunction(10), 5.0); // f(10) = 5

    // Тест 2: f(x) = x^9 (a0 = 1, остальные 0)
    modifyCoefficient(dialog, 0, 1);
    for (int i = 1; i < 10; ++i) {
        modifyCoefficient(dialog, i, 0);
    }
    QCOMPARE(dialog.calculateFunction(1), 1.0);  // f(1) = 1
    QCOMPARE(dialog.calculateFunction(-1), -1.0); // f(-1) = -1
}

void TestTask1::testIsSolvable() {
    task1 dialog;
    dialog.getC() = 0;
    dialog.getD() = 2;

    // Случай 1: f(0)=1, f(2)=большое положительное число (одинаковые знаки)
    modifyCoefficient(dialog, 9, 1);
    QVERIFY(!dialog.isSolvable());

    // Случай 2: // f(0)=-1, f(2)=большое положительное число (разные знаки)
    modifyCoefficient(dialog, 9, -1);
    QVERIFY(dialog.isSolvable());
}

void TestTask1::testChordMethod() {
    task1 dialog;
    dialog.getC() = 0;
    dialog.getD() = 2;
    dialog.getN() = 10;

    // f(x) = x - 1
    for (int i = 0; i < 9; ++i) modifyCoefficient(dialog, i, 0);
    modifyCoefficient(dialog, 8, 1); // a8 = 1 (коэффициент при x)
    modifyCoefficient(dialog, 9, -1); // a9 = -1 (свободный член)

    double root = dialog.solveByChordMethod(0, 2, 10);
    QVERIFY(qFabs(root - 1.0) < 0.001);
}


QTEST_MAIN(TestTask1)
#include "test_task1.moc"
