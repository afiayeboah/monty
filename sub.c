#include "monty.h"

/**
 * subtract_nodes - Subtracts the top element from the
 * second top element of the stack.
 *
 * @doubly: Pointer to the head of the linked list (stack).
 * @cline: Line number.
 * Return: No return.
 */
void subtract_nodes(stack_t **doubly, unsigned int cline)
{
	int node_count = 0;
	stack_t *current = NULL;

	current = *doubly;

	for (; current != NULL; current = current->next, node_count++)
	;

	if (node_count < 2)
	{
	dprintf(2, "L%u: can't sub, stack too short\n", cline);
	free_vglo();
	exit(EXIT_FAILURE);
	}

	current = (*doubly)->next;
	current->n -= (*doubly)->n;
	_pop(doubly, cline);
}
