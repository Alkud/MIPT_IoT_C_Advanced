// Поиск последовательности бит
// На вход программе подается беззнаковое 32-битное целое число N
// и натуральное число K (1 ≤ K ≤ 31).
// Требуется взять K подряд идущих битов числа N так,
// чтобы полученное число было максимальным.
// Программа должна вывести полученное число.

#include <stdio.h>
#include <inttypes.h>
#define NUM_BITS 32
 

int main(void)
{
    uint32_t N;
    uint8_t K;
    scanf("%u", &N);
    scanf("%hhu", &K);
    uint32_t mask = (1 << K) - 1;
    uint32_t max = 0;
    uint32_t remain = N & mask;
    while (N > 0)
    {
        if (remain > max)
        {
            max = remain;
        }
        N = N >> 1;
        remain = N & mask;
    }
    printf("%u\n", max);
    return 0;
}