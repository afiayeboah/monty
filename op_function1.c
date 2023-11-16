#include "monty.h"

/**
 * addnodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void addnodes(node **stack, unsigned int line_number)
{
    int sum;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        moreerror(8, line_number, "add");

    (*stack) = (*stack)->next;
    sum = (*stack)->val + (*stack)->prev->val;
    (*stack)->val = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * subnodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void subnodes(node **stack, unsigned int line_number)
{
    int difference;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        moreerror(8, line_number, "sub");

    (*stack) = (*stack)->next;
    difference = (*stack)->val - (*stack)->prev->val;
    (*stack)->val = difference;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * divnodes - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void divnodes(node **stack, unsigned int line_number)
{
    int quotient;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        moreerror(8, line_number, "div");

    if ((*stack)->val == 0)
        moreerror(9, line_number);

    (*stack) = (*stack)->next;
    quotient = (*stack)->val / (*stack)->prev->val;
    (*stack)->val = quotient;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * swapnodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void swapnodes(node **stack, unsigned int line_number)
{
    node *tmp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        moreerror(8, line_number, "swap");

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *stack;
    tmp->next = *stack;
    (*stack)->prev = tmp;
    tmp->prev = NULL;
    *stack = tmp;
}
