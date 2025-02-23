#include "print_results.h"

#include <math.h>
#include <stdio.h>

#include "bisections.h"
#include "simpson.h"

void FunctionList()
{
    printf("Тестируемые функции:\n");
    printf("\t f0(x) = 0 - пересечение с осью X\n");
    printf("\t f1(x) = 0.6 * x + 3\n");
    printf("\t f2(x) = (x - 2)^3 - 1\n");
    printf("\t f3(x) = 3 / x\n");
}

double PrintRootResult(const int func_idx_1, const int func_idx_2, const double a, const double b, const double eps)
{
    const RootResult r = root(functions_under_test[func_idx_1], functions_under_test[func_idx_2], a, b, eps);
    printf("Пересечение функций f%d и f%d на интервале [%.2lf, %.2lf] (затрачено итераций - %d):\n",
           func_idx_1, func_idx_2, a, b, r.num_iterations);
    printf("\tабсцисса: %.12lf, значение функции f%d: %.12lf, значение функции f%d: %.12lf\n",
           r.root, func_idx_1, r.f1, func_idx_2, r.f2);
    return r.root;
}

double PrintIntegralResult(const int func_idx, const double a, const double b, const double eps)
{
    const double i = integral(functions_under_test[func_idx], a, b, eps);
    printf("Площадь под функцией f%d на интервале [%.2lf, %.2lf]: %.2lf\n", func_idx, a, b, fabs(i));
    return fabs(i);
}