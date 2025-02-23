#ifndef BISECTIONS_H
#define BISECTIONS_H

#include "types.h"

/**
 * Структура, возвращаемая из метода поиска точки пересечения
 * графиков двух функций
 */
typedef struct RootResult
{
    /* корень уравнения - абсцисса точки пересечения графиков */
    double root;
    /* значение функции 1 в точке root */
    double f1;
    /* значение функции 2 в точке root */
    double f2;
    /* количество потраченных итераций, если -1, интервал задан неверно */
    int num_iterations;
} RootResult;

/**
 * Поиск точки пересечения графиков двух функций методом
 * деления отрезка пополам
 * @param f функция 1
 * @param g функция 2
 * @param a левая граница интервала поиска
 * @param b правая граница итервала поиска
 * @param eps1 точность
 * 
 * @returns структура RootResult
 * */ 
RootResult root(FuncType f, FuncType g, double a, double b, double eps1);

/**
 * Проверка, содержится ли точка пересечения функций в указанном интервале
 * и эта точка - единственная
 * @param f Функция 1
 * @param g Функция 2
 * @param a Левая граница интервала поиска
 * @param b Правая граница интервала поиска
 *
 * @returns 0 если пересечений нет или больше одного, 1 если точка пересечения единственная,
 *          2 - пересечение слева, 3 - пересечение справа
 *  */
int only_intersection_exists(FuncType f, FuncType g, double a, double b);

#endif