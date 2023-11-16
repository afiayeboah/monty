#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push_stack},
		{"pall", f_pall},
		{"pint", pint_str},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"queue", queue_mode},
	{"stack", stack_mode},
	{"add", add_nodes},
	{"nop", no_operation},
	{"sub", subtract_nodes},
	{"mul", multiply_nodes},
	{"div", divide_nodes},
	{"mod", modulo_nodes},
        {"pchar", print_char},
        {"pstr", pint_str},
	{"rotl", rotate_left},
        {"rotr", rotate_right},
	{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
	if (strcmp(instruct[i].opcode, opc) == 0)
	break;
	}

	return (instruct[i].f);
}
