// Отсортировать слова

// Дана строка, состоящая из английских букв и пробелов. В конце строки символ точка.
// Все слова разделены одним пробелом. Необходимо составить из слов односвязный список
// и упорядочить по алфавиту. Список необходимо удалить в конце программы.
// Для сравнение строк можно использовать strcmp. Необходимо использовать данную структуры организации списка.
// struct list {
//     char word[20];
//    struct list *next;
// }
// Необходимо реализовать односвязный список и обслуживающие его функции.
// add_to_list
// swap_elements
// print_list
// delete_list

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char word[20];
    struct list* next;
} list;

list* add_to_list(list* head, char word[])
{
    list* current = head;
    if (current == NULL)
    {
        current = calloc(1, sizeof(struct list));
    } else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = calloc(1, sizeof(struct list));
        current = current->next;
    }
    strcpy(current->word, word);
    current->next = NULL;
    return current;
}

void swap_elements(list* a, list* b)
{
    char tmp[20];
    strcpy(tmp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, tmp);
}

void print_list(list* head)
{
    list* current = head;
    while(current != NULL)
    {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

void delete_list(list* head)
{
    list* current = head;
    while(current != NULL)
    {
        list* tmp = current;
        current = current->next;
        free(tmp);
    }    
}

int main(void)
{
    char input_string[4095];
    fgets(input_string, 4095, stdin);
    char* word;
    word = strtok (input_string," .\n\r");
    list* head = NULL;
    list* current = head;
    // создание списка из введённой строки
    while (word != NULL)
    {
        current = add_to_list(current, word);
        if (head == NULL) 
        {
            head = current;
        }
        word = strtok(NULL, " .\n\r");
    }
    // пустая строка
    if (head == NULL)
    {
        return 0;
    }  
    // сортировка
    while (1)
    {
        current = head;
        while(current->next != NULL)
        {
            if (strcmp(current->word, current->next->word) > 0) {
                swap_elements(current, current->next);
                break;
            }
            current = current->next;
        }
        if (current->next == NULL)
        {
            break;
        }
    }
    print_list(head);
    delete_list(head);
    return 0;
}