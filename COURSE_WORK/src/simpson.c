#include "simpson.h"

#include <math.h>

double integral(const FuncType f, const double a, const double b, const double eps2)
{
    // Количество интервалов
    const int N = round((b - a) / eps2);
    // Расчет подынтегральной суммы
    // s1 - сумма элементов с нечетными индексами
     //s2 - сумма элементов с четными индексами
    double s1 = 0.0;
    double s2 = 0.0;
    for (int i = 0; i < N; ++i) {
        const double x = a + i*eps2;
        if (i % 2 != 0) {
            // четные индексы
            s1 += f(x);
        }
        else {
            // нечётные индексы
            s2 += f(x);
        }
    }
    return eps2 * (f(a) + 2.0 * s1 + 4.0 * s2 + f(b)) / 3.0;
}
