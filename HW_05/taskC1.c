// Префикс и суффикс

// На стандартном потоке ввода задаются две символьные строки,
// разделённые символом перевода строки. Каждая из строк не превышает подлине 104.
// В строках не встречаются пробельные символы. На стандартный поток вывода напечатайте два числа,
// разделённых пробелом:
// первое число — длина наибольшего префикса первой строки, являющегося суффиксом второй;
// второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксом второй.
// Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE (4095) // максимальный размер входной строки

uint16_t pref_suf_size(const char* test_string, uint16_t check_size,
                    const char* reference_string, uint16_t reference_size)
{
    uint16_t prefix_size = 0;
    while (prefix_size < check_size &&
           test_string[prefix_size] == reference_string[reference_size - check_size + prefix_size])
    {
        prefix_size += 1;
    }
    if (prefix_size != check_size)
    {
        return 0;
    }
    else
    {
        return prefix_size;
    }
}

uint16_t max_prefix_suffix_size(const char* test_string, uint16_t test_size,
                               const char* reference_string, uint16_t reference_size)
{
    uint16_t check_size = test_size < reference_size ? test_size : reference_size;
    uint16_t check_idx = reference_size - check_size;
    while (check_size > 0 && reference_string[check_idx] != test_string[0])
    {
        check_idx += 1;
        check_size -= 1;
    }
    uint16_t max_pref_suf_size = 0;
    while (check_size > max_pref_suf_size)
    {
        uint16_t ps_sz = pref_suf_size(test_string, check_size, reference_string, reference_size);
        if (ps_sz > max_pref_suf_size)
        {
            max_pref_suf_size = ps_sz;
        }
        uint16_t increment_size = (ps_sz > 0 ? ps_sz : 1);
        check_idx += increment_size;
        check_size -= increment_size;
        while (check_size > 0 && reference_string[check_idx] != test_string[0])
        {
            check_idx += 1;
            check_size -= 1;
        }        
    }
    return max_pref_suf_size;
}


int main(void)
{
    char string_a[MAX_STRING_SIZE];
    char string_b[MAX_STRING_SIZE];
    fgets(string_a, MAX_STRING_SIZE, stdin);
    string_a[strcspn(string_a, "\r\n")] = '\0';
    fgets(string_b, MAX_STRING_SIZE, stdin);
    string_b[strcspn(string_b, "\r\n")] = '\0';
    uint16_t size_a = strlen(string_a);
    uint16_t size_b = strlen(string_b);
    if (size_a == 0 || size_b == 0)
    {
        printf("0 0\n");
        return 0;
    }
    uint16_t a_b_max_pref_suf_size = max_prefix_suffix_size(string_a, size_a, string_b, size_b);
    uint16_t a_b_max_suf_pref_size = max_prefix_suffix_size(string_b, size_b, string_a, size_a);
    printf(
        "%hu %hu\n",
        a_b_max_pref_suf_size, a_b_max_suf_pref_size
    );
    return 0;
}