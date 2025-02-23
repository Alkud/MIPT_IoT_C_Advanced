#include "test_integral.h"

#include <stdio.h>
#include <math.h>

#include "simpson.h"

int test_integral(const int func_idx, const double a, const double b, const double eps, const double true_value)
{
    const FuncType func = functions_under_test[func_idx];
    const double test_value = integral(func, a, b, eps);
    printf("\tИтеграл функции f%d на интервале [%.2lf, %.2lf]:\n", func_idx, a, b);
    printf("\t\tтестовое значение: %.12lf | референсное значение: %.12lf | разность: %.12lf\n",
           test_value, true_value, fabs(true_value - test_value));
    if (fabs(test_value - true_value) >= eps) {
        return 0;
    }
    return 1;
}

int integral_algo_tests(void)
{
    int all_tests_passed = 0;
    for (int p = -3; p > -8; p -= 2) {
        const double eps = pow(10.0, p);
        printf("Интегрирование. EPS=%e\n", eps);
        for (int i = 0; i < 6; ++i) {
            const int func_idx = integral_function_indices[i];
            const double a = integral_intervals[i].a;
            const double b = integral_intervals[i].b;
            const double true_value = integral_quad_values[i];
            const int test_passed = test_integral(func_idx, a, b, eps, true_value);
            printf("\t\t%s\n", test_passed ? "Тест пройден" : "Тест НЕ пройден");
            if (test_passed) {
                all_tests_passed += 1;
            }
        }
    }
    return all_tests_passed == 6 ? 1 : 0;
}
