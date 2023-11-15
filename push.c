#include "monty.h"

/**
 * push_stack - Pushes an element to the stack.
 *
 * @stack: Pointer to the head of the linked list (stack)
 * @line_number: Line number
 *
 * Return: No return
 */
void push_stack(stack_t **stack, unsigned int line_number)
{
	int value, index;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (index = 0; vglo.arg[index] != '\0'; index++)
	{
		if (!isdigit(vglo.arg[index]) && vglo.arg[index] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	value = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(stack, value);
	else
		add_dnodeint_end(stack, value);
}

/**
 * f_pall - Prints the stack.
 *
 * @doubly: Pointer to the head of the linked list (stack).
 * @cline: Line number (not used).
 * Return: No return.
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
