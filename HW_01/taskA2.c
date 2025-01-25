// Циклический сдвиг
// На вход программе подается
// беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
// Требуется циклически сдвинуть битычисла N вправо на K битов и вывести полученное таким образом число. 

#include <stdio.h>
#include <inttypes.h>
#define NUM_BITS 32
 

uint32_t shift_right(uint32_t n, uint8_t k)
{
    return (n >> k) | (n << (NUM_BITS - k));
}

int main(void)
{
    uint32_t N;
    uint8_t K;
    scanf("%u", &N);
    scanf("%hhu", &K);
    printf("%u", shift_right(N, K));
    return 0;
}