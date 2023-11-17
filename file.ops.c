#include "monty.h"

/**
 * openfile - Opens file.
 * @fname: Namepath of file.
 *
 * Return: void
 */
void openfile(char *fname)
{
	FILE *fd = fopen(fname, "r");

	if (fname == NULL || fd == NULL)
		handleerror(2, fname);

	readfile(fd);
	fclose(fd);
}

/**
 * parseline - Parses lines and determines the format.
 * @buf: Buffer containing the line.
 * @line: Line number.
 * @format: Storage format. If 0, Nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 *
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parseline(char *buf, int line, int format)
{
char *opcode, *value;
	const char *delim = "\n ";

	if (buf == NULL)
	handleerror(4);

	opcode = strtok(buf, delim);
    if (opcode == NULL)
        return (format);
    value = strtok(NULL, delim);

    if (strcmp(opcode, "stack") == 0)
        return (0);
    if (strcmp(opcode, "queue") == 0)
        return (1);

    findfunc(opcode, value, line, format);
    return (format);
}

/**
 * readfile - Reads a file.
 * @fd: Pointer to file descriptor.
 *
 * Return: void
 */
void readfile(FILE *fd)
{
    int line_number, format = 0;
    char *buffer = NULL;
    size_t len = 0;

    for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
    {
        format = parseline(buffer, line_number, format);
    }
    free(buffer);
}

/**
 * charscount - Counts characters in a file.
 * @fd: Pointer to file descriptor.
 *
 * Return: Number of characters.
 */
int charscount(FILE *fd)
{
    int count = 0;
    int ch;

    if (fd == NULL)
        handleerror(4);

    while ((ch = fgetc(fd)) != EOF)
    {
        count++;
    }

    rewind(fd);
    return count;
}

/**
 * findfunc - Finds the right function for the opcode.
 * @opcode: Opcode.
 * @val: Argument of opcode.
 * @line: Line number.
 * @format: Storage format. If 0, Nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 *
 * Return: void
 */

void findfunc(char *opcode, char *val, int line, int format)
{
	int i;
	int flag;

    instruction_t instruct[] = {
        {"push", addtostack},
        {"pall", printstack},
        {"pint", printtop},
        {"pop", poptop},
        {"nop", nop},
        {"swap", swapnodes},
        {"add", addnodes},
        {"sub", subnodes},
        {"div", divnodes},
        {"mul", mulnodes},
        {"mod", modnodes},
        {"pchar", printchar},
        {"pstr", printstr},
        {"rotl", rotleft},
        {"rotr", rotright},
        {NULL, NULL}
    };
	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; instruct[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instruct[i].opcode) == 0)
		{
			callfunc(instruct[i].f, opcode, val, line, format);
			flag = 0;
		}
	}
	if (flag == 1)
		handleerror(3, line, opcode);
}

/**
 * callfunc - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: String representing the opcode.
 * @val: String representing a numeric value.
 * @line: Line number for the instruction.
 * @format: Format specifier. If 0, Nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 */
void callfunc(opfunc func, char *op, char *val, int line, int format)
{

if (line < 0)
   line = 0;

if (strcmp(op, "push") == 0)
{
   if (format == 0)
   {
      if (*val == '-')
      {
	       val++;
         format = -1;
      }
      else
      {
	      format = 1;
      }
   }
   else if (format == -1)
   {
	   val++;
   }
   else
   {
	    
	    func(&head, line);
    }
}
}

