#include "monty.h"

/**
 * mulnodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void mulnodes(node **stack, unsigned int line_number)
{
    int product;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        moreerror(8, line_number, "mul");

    (*stack) = (*stack)->next;
    product = (*stack)->val * (*stack)->prev->val;
    (*stack)->val = product;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * modnodes - Computes the remainder of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void modnodes(node **stack, unsigned int line_number)
{
    int remainder;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        moreerror(8, line_number, "mod");

    if ((*stack)->val == 0)
        moreerror(9, line_number);

    (*stack) = (*stack)->next;
    remainder = (*stack)->val % (*stack)->prev->val;
    (*stack)->val = remainder;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
