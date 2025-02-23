#include "bisections.h"

#include <math.h>

int only_intersection_exists(const FuncType f, const FuncType g, const double a, const double b)
{
    // Если на обоих концах интервала одна функция больше (меньше) другой,
    // разница значений функция в этих точках имеет одинаковый знак.
    // Это значит, либо пересечения нет, либо пересечений несколько.
    // В случае одного пересечения на одном из концов функция f больше (меньше)
    // функции g, на другом - функция f меньше (больше) функции g,
    // и тогда произведение разностей этих значений меньше 0.
    const double left = f(a) -g(a);
    const double right = f(b) - g(b);
    if (left == 0.0 && right != 0.0) {
        // левая граница - точка пересечения
        return 2;
    } else if (left != 0.0 && right == 0.0) {
        // правая граница - точка пересечения
        return 3;
    } else if (left == 0.0 && right == 0.0) {
        // обе границы - точки пересечения
        return  0;
    } else {
        // 1 - пересечение единственное,
        // 0 - пересечений нет, либо больше одного
        return (left * right < 0 ? 1 : 0);
    }
}


RootResult root(const FuncType f, const FuncType g, double a, double b, const double eps1)
{
    RootResult res = {
        .root = 0.0,
        .f1 = 0.0,
        .f2 = 0.0,
        .num_iterations = 0
    };
    // Проверяем, действительно ли на указанном интервале
    // графики функций пересекаются только один раз
    const int initial_check = only_intersection_exists(f, g, a, b);
    if (initial_check == 0) {
        // пересечений нет или больше одного - возвращаем
        // число итераций равное -1 - знак ошибки
        res.root = 0.0;
        res.f1 = 0.0;
        res.f2 = 0.0;
        res.num_iterations = -1;
        return res;
    } else if (initial_check == 2) {
        res.root = a;
        res.f1 = f(a);
        res.f2 = g(a);
        res.num_iterations = 0;
        return res;
    } else if (initial_check == 3) {
        res.root = b;
        res.f1 = f(b);
        res.f2 = g(b);
        res.num_iterations = 0;
        return res;
    }
    double x0 = (a + b) / 2.0;
    res.num_iterations = 1;
    while (fabs(a - b) >= eps1) {
        const int check_result = only_intersection_exists(f, g, a, x0);
         if (check_result == 2) {
            res.root = a;
            break;
        } else if (check_result == 3) {
            res.root = b;
            break;
        }
        if (check_result == 0) {
            // если нет пересечений графиков на интервале [a, x0],
            // смещаем левую границу в x0
            a = x0;
        } else {
            // иначе - смещаем правую в x0
            b = x0;
        }
        // делим текущий отрезок пополам
        x0 = (a + b) / 2.0;
        res.num_iterations += 1;
    }
    res.root = x0;
    res.f1 = f(x0);
    res.f2 = g(x0);
    return res;
}
