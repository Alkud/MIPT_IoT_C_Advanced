#include "test_root.h"

#include <math.h>
#include <tgmath.h>
#include <stdio.h>

#include "bisections.h"

int test_root(const int func_idx_1, const int func_idx_2,
              const double a, const double b, const double eps, const double true_value)
{
    const FuncType func1 = functions_under_test[func_idx_1];
    const FuncType func2 = functions_under_test[func_idx_2];
    const RootResult test_result = root(func1, func2, a, b, eps);
    printf("\tПересечение функций f%d и f%d на интервале [%.2lf, %.2lf]:\n",
           func_idx_1, func_idx_2, a, b);
    printf("\t\tтестовое значение: %.12lf | референсное значение: %.12lf | разность: %.12lf\n",
           test_result.root, true_value, fabs(true_value - test_result.root));
    if (fabs(test_result.root - true_value) >= eps || test_result.num_iterations < 0) {
        return 0;
    }
    return 1;
}

int root_algo_tests(void)
{
    int all_tests_passed = 0;
    for (int p = -3; p > -12; p -= 2) {
        const double eps = pow(10.0, p);
        printf("Поиск корней. EPS=%e\n", eps);
        for (int i = 0; i < 6; ++i) {
            const int func_idx_1 = root_function_indices[i][0];
            const int func_idx_2 = root_function_indices[i][1];
            const double a = root_intervals[i].a;
            const double b = root_intervals[i].b;
            const double true_root_x = brent_roots[i].x;
            const double true_root_y = brent_roots[i].y;
            const int test_passed = test_root(func_idx_1, func_idx_2, a, b, eps, true_root_x);
            printf("\t\t%s\n", test_passed ? "Тест пройден" : "Тест НЕ пройден");
            if (test_passed) {
                all_tests_passed += 1;
            }
        }
    }
    return all_tests_passed == 6 ? 1 : 0;
}
