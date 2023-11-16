#include "monty.h"
/**
 * f_pall - Prints the stack.
 *
 * @doubly: Pointer to the head of the linked list (stack).
 * @cline: Line number (not used).  Return: No return.
 */

void f_pall(stack_t **doubly, unsigned int cline)
{
        stack_t *current;
        (void)cline;

        current = *doubly;

        if (current == NULL)
        return;

        while (current)
        {
        printf("%d\n", current->n);
        current = current->next;
        }
}
