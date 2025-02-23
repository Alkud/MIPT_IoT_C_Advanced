#ifndef TEST_INTEGRAL_H
#define TEST_INTEGRAL_H

#include "types.h"
#include "test_root.h"

/**
 * Индексы функций для определения площадей
 */
static const int integral_function_indices[] = {3, 1, 2, 1, 3, 2};

/**
*   Тестовые интервалы интегрирования функции
*/
static const Interval integral_intervals[] = {
    {brent_roots[0].x, brent_roots[2].x},
    {brent_roots[0].x, brent_roots[1].x},
    {brent_roots[2].x, brent_roots[4].x},
    {brent_roots[1].x, brent_roots[3].x},
    {brent_roots[3].x, brent_roots[5].x},
    {brent_roots[4].x, brent_roots[5].x}
};

/**
* Результаты численного интегрирования в scipy (QUADPACK)
*/
static const double integral_quad_values[] = {
    -9.53406385471627,
    -0.2188470506254732,
    -9.332280661371847,
    10.28115294937521,
    4.003469694956835,
    0.10465110984503151
};

/**
 * Тест метода деления отрезка пополам
 * @param func_idx индекс функции в списке тестируемых
 * @param a левая граница интервала поиска
 * @param b правая граница итервала поиска
 * @param eps точность
 * @param true_value истинное значение корня
 *
 * @returns 0 в случае успеха, -1 иначе
 *  */
int test_integral(int func_idx, double a, double b, double eps, double true_value);

/**
 * Полный тест алгоритма интегрирования
 * @return 1 если все тесты пройдены, 0 иначе
 */
int integral_algo_tests(void);

#endif //TEST_INTEGRAL_H
