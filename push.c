#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int num, index;

	if (!global.param)
	{
	dprintf(2, "L%u: ", line_number);
	dprintf(2, "usage: push integer\n");
	free_global();
	exit(EXIT_FAILURE);
	}

	for (index = 0; global.param[index] != '\0'; index++)
	{
	if (!isdigit(global.param[index]) && globak.param[index] != '-')
	{
	dprintf(2, "L%u: ", line_number);
	dprintf(2, "usage: push integer\n");
	free_global();
	exit(EXIT_FAILURE);
	}

	num = atoi(global.param);

	if (global.is_stack == 1)
	add_node_to_start(stack, num);
	else
	add_node_to_end(stack, num);

}
}
