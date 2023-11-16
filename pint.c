#include "monty.h"

/**
 * pint_str - Prints the value at the top of the stack.
 *
 * @stack: Pointer to the head of the linked list (stack).
 * @line_number: Line number.
 * Return: No return.
 */
void pint_str(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
	dprintf(2, "L%u: ", line_number);
	dprintf(2, "can't pint, stack empty\n");
	free_global();
	exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
