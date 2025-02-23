#include <stdio.h>
#include <locale.h>
#include <print_results.h>
#include <simpson.h>

#include "program_arguments.h"
#include "test_root.h"
#include "test_integral.h"


int main(const int argc, char* argv[])
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    ProgramArguments arguments = {
            .eps1 = 1e-14,
            .eps2 = 1e-7,
            .test_mode = 0
    };

    const int need_help = ParseArguments(argc, argv, &arguments);

    if (need_help) {
        PrintHelp();
        return 0;
    }

    // Список тестируемых функций
    FunctionList();
    if (arguments.test_mode) {
        root_algo_tests();
        integral_algo_tests();
        return 0;
    }
    // Вывод точек пересечения функций
    const double r0 = PrintRootResult(1, 3, root_intervals[0].a, root_intervals[0].b, arguments.eps1);
    const double r1 = PrintRootResult(1, 0, root_intervals[1].a, root_intervals[1].b, arguments.eps1);
    const double r2 = PrintRootResult(2, 3, root_intervals[2].a, root_intervals[2].b, arguments.eps1);
    const double r3 = PrintRootResult(1, 3, root_intervals[3].a, root_intervals[3].b, arguments.eps1);
    const double r4 = PrintRootResult(2, 0, root_intervals[4].a, root_intervals[4].b, arguments.eps1);
    const double r5 = PrintRootResult(2, 3, root_intervals[5].a, root_intervals[5].b, arguments.eps1);
    // Вывод площадей под кривыми
    const double s_lower_0 = PrintIntegralResult(3, r0, r2, arguments.eps2);
    const double s_lower_1 = PrintIntegralResult(1, r0, r1, arguments.eps2);
    const double s_lower_2 = PrintIntegralResult(2, r2, r4, arguments.eps2);
    const double s_upper_0 = PrintIntegralResult(1, r1, r3, arguments.eps2);
    const double s_upper_1 = PrintIntegralResult(3, r3, r5, arguments.eps2);
    const double s_upper_2 = PrintIntegralResult(2, r4, r5, arguments.eps2);
    // Вывод площади, образованной пересечением графиков функций
    const double S = s_lower_0 - s_lower_1 + s_lower_2 + s_upper_0 + s_upper_1 - s_upper_2;
    printf("ПЛОЩАДЬ, ОБРАЗВАННАЯ ГРАФИКАМИ ФУНКЦИЙ: %.2lf\n", S);

    return 0;
}