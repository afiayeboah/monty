#include "monty.h"

/**
 * add_nodes - Adds the top two elements of the stack.
 *
 * @stack: Pointer to the head of the linked list (stack).
 * @line_number: Line number.
 * Return: No return.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int node_count = 0;
	stack_t *current = NULL;

	current = *stack;

	for (; current != NULL; current = current->next, node_count++)
		;

	if (node_count < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_global();
		exit(EXIT_FAILURE);
	}

	current = (*stack)->next;
	current->n += (*stack)->n;
	_pop(stack, line_number);
}
