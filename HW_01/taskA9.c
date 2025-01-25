// Упаковать массив
// В программе реализована структура данных:
// struct pack_array {
//     uint32_t array; // поле для хранения упакованного массива из 0 и 1
//     uint32_t count0 : 8; // счетчик нулей в array
//     uint32_t count1 : 8; // счетчик единиц в array
// }
// Необходимо реализовать программу, которая упаковывает переданный ей массив
// из 32-ух элементов 0 и 1 в указанную структуру данных.
// Функция должна строго соответствовать прототипу:
// void array2struct(int [], struct pack_array *)

#include <stdio.h>
#include <inttypes.h>
#define NUM_BITS 32

struct pack_array {
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(int array[], struct pack_array* pack)
{
    pack->array = 0;
    pack->count0 = 0;
    pack->count1 = 0;
    for (uint8_t i = 0; i < NUM_BITS; ++i)
    {
        if (array[i])
        {
            pack->count1 += 1;
            pack->array += 1 << i;
        } else
        {
            pack->count0 += 1;
        }
    }
}

int main(void)
{
    int input[NUM_BITS] = {0,};
    for (uint8_t i = 0; i < NUM_BITS; ++i)
    {
        scanf("%hhu", &input[NUM_BITS-1-i]);
    }
    struct pack_array pack;
    array2struct(input, &pack);
    printf("%u %hhu %hhu\n", pack.array, pack.count0, pack.count1);
    return 0;
}