// Польская запись
// Необходимо вычислить выражение написанное в обратной польской записи.
// На вход подается строка состоящая из целых, неотрицательных чисел и арифметических символов.
// В ответ единственное целое число - результат.

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE (100)

struct CalcStack
{
    uint32_t buffer[STACK_SIZE];
    uint8_t idx;
    uint8_t size;
};

void init_stack(struct CalcStack* stack)
{
    stack->idx = 0;
    stack->size = 0;
    for (uint8_t i = 0; i < STACK_SIZE; ++i)
    {
        stack->buffer[i] = 0;
    }
}

void push_to_stack(struct CalcStack* stack, uint32_t n)
{
    stack->idx += 1;
    if (stack->idx >= STACK_SIZE)
    {
        stack->idx = 0;
    }
    stack->buffer[stack->idx] = n;
    stack->size += 1;
}

uint32_t pop_from_stack(struct CalcStack* stack)
{
    uint32_t res = stack->buffer[stack->idx];
    if (stack->idx > 0)
    {
        stack->idx -= 1;
    }
    else
    {
        stack->idx = STACK_SIZE - 1;
    }
    stack->size -= 1;
    return res;
}

uint8_t is_operation(char c)
{
    if (c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    else
        return 0;
}

void apply_operation(struct CalcStack* stack, char op)
{
    uint32_t b = pop_from_stack(stack);
    uint32_t a = pop_from_stack(stack);
    switch (op)
    {
    case '+':
        push_to_stack(stack, (a + b));
        break;
    case '-':
        push_to_stack(stack, (a - b));
        break;
    case '*':
        push_to_stack(stack, (a * b));
        break;
    case '/':
        push_to_stack(stack, (a / b));
        break;
    default:
        break;
    }
}

int main(void)
{
    char input_string[4095];
    scanf("%s", input_string);
    uint32_t len;
    uint32_t operand;
    struct CalcStack calc_stack;
    init_stack(&calc_stack);
    while (1)
    {
        len = strlen(input_string);
        if (input_string[len - 1] == '.')
        {
            input_string[len - 1] = '\0';
            break;
        }
        if (len > 1)
        {
            sscanf(input_string, "%d", &operand);
            push_to_stack(&calc_stack, operand);
        }
        else
        {
            if (is_operation(input_string[0]))
            {
                apply_operation(&calc_stack, input_string[0]);
            }
            else
            {
                sscanf(input_string, "%d", &operand);
                push_to_stack(&calc_stack, operand);
            }
        }
        if (getchar() == '\n')
        {
            break;
        }
        scanf("%s", input_string);
    }
    apply_operation(&calc_stack, input_string[0]);
    printf("%d\n", pop_from_stack(&calc_stack));
    return 0;
}