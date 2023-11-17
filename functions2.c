#include "monty.h"

/**
 * addtostack - Adds a node to the stack.
 * @stack: Pointer to the new node.
 * @line_number: Integer representing the line number of the opcode.
 */
void addtostack(node **stack, unsigned int line_number)
{
    node *new_node;

    if (stack == NULL)
        exit(EXIT_FAILURE);

    new_node = createnode(line_number);
    if (new_node == NULL)
        exit(EXIT_FAILURE);

    new_node->val = line_number;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * printstack - Prints the elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void printstack(node **stack, unsigned int line_number)
{
    node *tmp;

    (void)line_number;

    if (stack == NULL)
        exit(EXIT_FAILURE);

    tmp = *stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->val);
        tmp = tmp->next;
    }
}

/**
 * printtop - Prints the value of the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void printtop(node **stack, unsigned int line_number __attribute__((unused)))
{ if (stack == NULL || *stack == NULL)
        exit(EXIT_FAILURE);

    printf("%d\n", (*stack)->val);
}

/**
 * poptop - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void poptop(node **stack, unsigned int line_number __attribute__((unused)))
{
    node *tmp;

    if (stack == NULL || *stack == NULL)
        exit(EXIT_FAILURE);

    tmp = *stack;
    *stack = tmp->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(tmp);
}
