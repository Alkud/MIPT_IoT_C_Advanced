#ifndef PRINT_RESULTS_H
#define PRINT_RESULTS_H

#include "types.h"
/**
 * Вывод списка тестируемых функций
 */
void FunctionList();

/**
 * Вывод результата поиска точки пересечения функций на заданном интервале
 * @param func_idx_1 индекс 1-ой функции в списке тестируемых
 * @param func_idx_2 индекс 2-ой функции в списке тестируемых
 * @param a левая граница интервала
 * @param b правая граница интервала
 * @param eps точность
 */
double PrintRootResult(int func_idx_1, int func_idx_2, double a, double b, double eps);

/**
 * Вывод значения площади под графиком функции на интервале
 * @param func_idx индекс функции в списке тестируемых
 * @param a левая граница интервала
 * @param b правая граница интервала
 * @param eps шаг интегрирования
 */
double PrintIntegralResult(int func_idx, double a, double b, double eps);

#endif //PRINT_RESULTS_H
