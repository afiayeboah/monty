#include "monty.h"

/**
 * divide_nodes - Divides the second element by the top element of the stack.
 * @doubly: Pointer to the stack head
 * @cline: Line number
 *
 * Return: No return
 */
void divide_nodes(stack_t **doubly, unsigned int cline)
{
	stack_t *current;
	int length = 0, result;

	current = *doubly;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", cline);
		fclose(global.file);
		free_global();
		free_doubly_list(*doubly);
		exit(EXIT_FAILURE);
	}

	current = *doubly;

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", cline);
		fclose(global.file);
		free_global();
		free_doubly_list(*doubly);
		exit(EXIT_FAILURE);
	}

	result = current->next->n / current->n;
	current->next->n = result;
	*doubly = current->next;
	free(current);
}
