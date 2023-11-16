#include "monty.h"

/**
 * handleerror - Prints appropriate error messages based on the error code.
 * @errorcode: The error codes are as follows:
 * (1) => No file or more than one file provided.
 * (2) => Unable to open or read the provided file.
 * (3) => Invalid instruction in the file.
 * (4) => Memory allocation failure.
 * (5) => Parameter for "push" is not an integer.
 */
void handleerror(int errorcode, ...)
{
	va_list args;
	char *op;
	int lineNum;

	va_start(args, errorcode);
	switch (errorcode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			lineNum = va_arg(args, int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	freenodes();
	exit(EXIT_FAILURE);
}

/**
 * moreerror - Handles additional errors.
 * @errorCode: The error codes are as follows:
 * (6) => Stack is empty for pint.
 * (7) => Stack is empty for pop.
 * (8) => Stack is too short for the operation.
 * (9) => Division by zero.
 */
void moreerror(int errorcode, ...)
{
	va_list args;
	char *op;
	int lineNum;

	va_start(args, errorcode);
	switch (errorcode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			lineNum = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lineNum, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	freenodes();
	exit(EXIT_FAILURE);
}

/**
 * stringerror - Handles string-related errors.
 * @errorcode: The error codes are as follows:
 * (10) => The number inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */
void stringerror(int errorcode, ...)
{
	va_list args;
	int lineNum;

	va_start(args, errorcode);
	lineNum = va_arg(args, int);
	switch (errorcode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNum);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNum);
			break;
		default:
			break;
	}
	freenodes();
	exit(EXIT_FAILURE);
}
