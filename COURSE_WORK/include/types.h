#ifndef TYPES_H
#define TYPES_H

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct Interval {
    double a;
    double b;
} Interval;

/**
 * Тип для функции одной переменной
 */
typedef  double(*FuncType)(double);

/**
 * Вспомогательная функция, всегда возвращающая ноль
 * для поиска пересечения графика функции с осью x
 */
static double return_zero(double)
{
    return 0.0;
}
static const FuncType zero_fun = &return_zero;

static double func_one(const double x)
{
    return 0.6 * x + 3.0;
}
static const FuncType f1 = &func_one;

static double func_two(const double x)
{
    const double d = x - 2;
    return d*d*d -1 ;
}
static const FuncType f2 = &func_two;

static double func_three(const double x)
{
    if (x == 0.0) {
        return __DBL_MAX__;
    }
    return 3.0 / x;
}
static const FuncType f3 = &func_three;

static FuncType functions_under_test [] = {zero_fun, f1, f2, f3};

#endif
