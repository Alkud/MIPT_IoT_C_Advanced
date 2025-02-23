#ifndef SIMPSON_H
#define SIMPSON_H

#include "types.h"

/**
 * Численное интегрирование методом Симпсона
 * @param f функция
 * @param a левая граница интервала
 * @param b правая граница интервала
 * @param eps2 шаг интегрирования
 * @return значение интеграла
 */
double integral(FuncType f, double a, double b, double eps2);

#endif //SIMPSON_H
