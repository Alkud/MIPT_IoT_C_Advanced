// Максимальный блок
// Описана структура данных
// typedef struct list {
//    uint64_t address;
//    size_t size;
//    char comment[64];
//    struct list *next;
// } list;
// Требуется реализовать только одну функцию, которая в данном списке находит адрес блока памяти занимающий больше всего места.
// Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0. Если есть несколько таких блоков, то вернуть адрес любого из них.
// Прототип функции:
// uint64_t findMaxBlock(list *head)

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t findMaxBlock(list *head)
{
    list* current = head;
    size_t maxSize = 0;
    uint64_t maxAddress = 0;
    while(current != NULL)
    {
        if (current->size > maxSize)
        {
            maxSize = current->size;
            maxAddress = current->address;
        }
        current = current->next;
    }
    return maxAddress;
}

void freeList(list* head)
{
    list* current = head;
    list* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main(void)
{
    uint64_t N = 10;
    struct list* head = malloc(sizeof(list));
    struct list* current = head;
    srand(time(NULL));
    
    size_t maxSize = 0;
    uint64_t maxAddress = 0;    
    for (uint64_t i = 0; i < N; ++i)
    {
        current->size = rand();
        current->address = (uint64_t)current;
        if (current->size > maxSize)
        {
            maxSize = current->size;
            maxAddress = current->address;
        }
        current->next = malloc(sizeof(list));
        printf("%lu - %lu\n", current->address, current->size);
        current = current->next;
    }
    current->size = rand();
    current->address = (uint64_t)current;
    if (current->size > maxSize)
    {
        maxSize = current->size;
        maxAddress = current->address;
    }
    printf("%lu - %lu\n", current->address, current->size);
    current->next = NULL;

    printf("%lu\n", maxAddress);
    uint64_t testMaxAddress = findMaxBlock(head);
    printf("%lu\n", testMaxAddress);
    freeList(head);
    if (maxAddress == testMaxAddress)
    {
        return 0;
    } else
    {
        return - 1;
    }
}