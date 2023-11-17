#include "monty.h"

/**
 * printchar - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void printchar(node **stack, unsigned int line_number)
{
    int ascii;

    if (stack == NULL || *stack == NULL)
        str_error(11, line_number);

    ascii = (*stack)->val;
    if (ascii < 0 || ascii > 127)
        str_error(10, line_number);
    printf("%c\n", ascii);
}

/**
 * printstr - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void printstr(node **stack, unsigned int line_number __attribute__((unused)))
{
    int ascii;
    node *tmp;

    if (stack == NULL || *stack == NULL)
    {
        printf("\n");
        return;
    }

    tmp = *stack;
    while (tmp != NULL)
    {
        ascii = tmp->val;
        if (ascii <= 0 || ascii > 127)
            break;
        printf("%c", ascii);
        tmp = tmp->next;
    }
    printf("\n");
}

/**
 * rotleft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void rotleft(node **stack, unsigned int line_number __attribute__((unused)))
{
    node *tmp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    tmp = *stack;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stack;
    (*stack)->prev = tmp;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

/**
 * rotright - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void rotright(node **stack, unsigned int line_number __attribute__((unused)))
{
    node *tmp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    tmp = *stack;

    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stack;
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    (*stack)->prev = tmp;
    (*stack) = tmp;
}
