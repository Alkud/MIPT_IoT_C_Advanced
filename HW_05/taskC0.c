// Вычеркивание
//
// Сколько различных трехзначных чисел можно получить из заданного натурального N,
// вычеркивая цифры из его десятичной записи?


#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STRING_SIZE (4095) // максимальный размер входной строки
#define FLAGS_NUMBER (1032/64) // кол-во 64-битных чисел для хранения 1000 битов

void bit_index(uint16_t n, uint8_t* cell_idx, uint8_t* bit_idx)
{
    *cell_idx = n / 64;
    *bit_idx = n - *cell_idx*64;
}

uint8_t get_number_flag(uint16_t n, uint64_t* flags)
{
    uint8_t cell_idx, bit_idx;
    bit_index(n, &cell_idx, &bit_idx);
    uint64_t test = (flags[cell_idx] >> bit_idx) & 1;
    return test;
}

void set_number_flag(uint16_t n, uint64_t* flags)
{
    uint8_t cell_idx, bit_idx;
    bit_index(n, &cell_idx, &bit_idx);
    uint64_t mask = ((uint64_t)1 << bit_idx);
    flags[cell_idx] |= mask;
}

uint64_t compress_repeating_symbols(char* string, uint64_t size, uint64_t* number_flags, uint64_t* unique_count)
{
    if (size == 0)
    {
        // пустая строка
        return 0;
    }
    // размер новой строки, в которой все повторяющиеся последовательности сжаты максимум до 3-ёх символов
    uint64_t compressed_size = 0;
    // счётчик повторяющихся соседних цифр
    uint32_t adjacent_count = 0;
    // позиция записи сжатой строки
    uint32_t write_idx = 0;
    uint32_t read_idx = 0;
    // пропускаем нули в начале
    while(string[read_idx] == '0')
    {
        read_idx += 1;
    }
    char current_symbol = string[read_idx];
    compressed_size = 1;
    adjacent_count = 1;
    read_idx += 1;
    string[0] = current_symbol;
    write_idx += 1;
    for (; read_idx < size; ++read_idx)
    {
        if (string[read_idx] == current_symbol)
        {
            // встречаем повторяющиеся символы
            // увеличиваем счётчик повторений
            adjacent_count += 1;
            if (adjacent_count == 3)
            {
                if (current_symbol != '0')
                {
                    // фиксируем число из трёх одинаковых цифр
                    uint16_t d = current_symbol - '0';
                    uint16_t n = d*100 + d*10 + d;
                    if (!get_number_flag(n, number_flags))
                    {
                        set_number_flag(n, number_flags);
                        *unique_count += 1;
                    }
                }
                continue;
            }
            else if (adjacent_count > 3)
            {
                // если подряд идущих одинаковых символов 3 и более, переходим к следующему символу
                continue;
            }
        }
        else
        {
            // встеритился новый символ
            // обновляем образец для сравнения
            current_symbol = string[read_idx];
            // сбрасываем счётчик повторений
            adjacent_count = 1;
        }
        // сохраняем символ в сжатую строку
        string[write_idx] = current_symbol;        
        compressed_size += 1;
        // обновляем позицию запси
        write_idx += 1;     
    }
    return compressed_size;
}



int main(void)
{
    uint64_t N;
    char input_string[MAX_STRING_SIZE];
    scanf("%s", &input_string[0]);
    N = strlen(input_string);
    uint64_t number_flags [FLAGS_NUMBER];
    for (uint8_t k = 0; k < FLAGS_NUMBER; ++k)
    {
        number_flags[k] = 0;
    }
    uint64_t unique_count = 0;
    // сжимаем повторяющиеся цифры и одновременно отмечаем 3-значные числа из одинаковых цифр
    uint64_t compressed_size = compress_repeating_symbols(input_string, N, number_flags, &unique_count);
    for (uint16_t i = 0; i < compressed_size - 2; ++i)
    {
        if (input_string[i] == '0') continue;
        // перебираем комбинации цифр
        for (int j = i + 1; j < compressed_size - 1; ++j)
            for (int k = j + 1; k < compressed_size; ++k)
            {
                uint16_t d2 = input_string[i] - '0';
                uint16_t d1 = input_string[j] - '0';
                uint16_t d0 = input_string[k] - '0';
                uint16_t n = d2*100 + d1*10 + d0;
                // проверяем, встречалось ли число
                uint8_t test = get_number_flag(n, number_flags);
                if (!test)
                {
                    set_number_flag(n, number_flags);
                    unique_count += 1;
                }                
            }
    }
    printf("%lu\n", unique_count);
    return 0;
}

