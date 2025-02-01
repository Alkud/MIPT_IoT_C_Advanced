// Всего памяти

// Описана структура данных для хранения информации об использованной памяти:
// typedef struct list {
//    void *address;
//    size_t size;
//    char comment[64];
//    struct list *next;
// } list;
// Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется. Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0.
// Прототип функции:
// size_t totalMemoryUsage(list *head)

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t totalMemoryUsage(list *head)
{
    list* current = head;
    uint64_t totalMemory = 0;
    while(current != NULL)
    {
        totalMemory += current->size;
        current = current->next;
    }
    return totalMemory;
}


int main(void)
{
    uint64_t N = 10;
    struct list* head = malloc(sizeof(list));
    struct list* current = head;
    srand(time(NULL));
    
    size_t totalMemory = 0;
    for (uint64_t i = 0; i < N; ++i)
    {
        current->size = rand();
        current->address = (uint64_t)current;
        totalMemory += current->size;
        current->next = malloc(sizeof(list));
        printf("%lu - %lu\n", current->address, current->size);
        current = current->next;
    }
    current->size = rand();
    current->address = (uint64_t)current;
    totalMemory += current->size;
    printf("%lu - %lu\n", current->address, current->size);
    current->next = NULL;

    printf("%lu\n", totalMemory);
    uint64_t testTotal = totalMemoryUsage(head);
    printf("%lu\n", testTotal);
    if (totalMemory == testTotal)
    {
        return 0;
    } else
    {
        return - 1;
    }
}