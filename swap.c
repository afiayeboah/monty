#include "monty.h"

/**
 * swap_stack - Swaps the top two elements of the stack.
 *
 * @stack: Pointer to the head of the linked list (stack).
 * @line_number: Line number.
 * Return: No return.
 */
void swap_stack(stack_t **stack, unsigned int line_number)
{
	int node_count = 0;
	stack_t *current = NULL;

	current = *stack;

	for (; current != NULL; current = current->next, node_count++)
		;

	if (node_count < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_global();
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = (*stack)->next;
	current->next = (*stack)->next;
	current->prev = *stack;
	(*stack)->next = current;
	(*stack)->prev = NULL;
}
