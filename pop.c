#include "monty.h"
#include "monty.h"

/**
 * pop_stack - Removes the top element of the stack.
 *
 * @stack: Pointer to the head of the linked list (stack).
 * @line_number: Line number.
 * Return: No return.
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(global.file);
		free(global.curr_line);
		free_doubly_list(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = current->next;
	free(current);
}
