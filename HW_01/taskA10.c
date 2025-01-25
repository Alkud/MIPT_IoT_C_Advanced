// Распаковать порядок
// Необходимо реализовать программу, которой на входе передаётся
// вещественное число в типе float, она возвращает порядок который
// хранится в поле EXP в виде десятичного целого числа.
// Функция должна строго соответствовать прототипу
// int extractExp(float)

#include <stdio.h>
#include <inttypes.h>

int extractExp(float f)
{
    union
    {
        float value;
        struct
        {
            uint32_t M: 23;
            uint32_t EXP: 8;
            uint32_t S: 1;
        } pack;
    } packed_float;
    packed_float.value = f;
    return packed_float.pack.EXP;
}

int main(void)
{
    float input = 0.0F;
    scanf("%f", &input);
    printf("%d\n", extractExp(input));
    return 0;
}