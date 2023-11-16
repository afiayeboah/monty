#include "monty.h"

global_t global;

/**
 * free_global - Frees the global variables
 *
 * Return: No return
 */
void free_global(void)
{
    free_doubly_list(global.head);
    free(global.input_buffer);
    fclose(global.file);
}

/**
 * start_global - Initializes the global variables
 *
 * @fd: File descriptor
 * Return: No return
 */
void start_global(FILE *fd)
{
    global.is_stack = 1;
    global.curr_line = NULL;
    global.param = NULL;
    global.head = NULL;
    global.file = fd;
    global.input_buffer = NULL;
}

/**
 * check_input - Checks if the file exists and can be opened
 *
 * @argc: Argument count
 * @argv: Argument vector
 * Return: File struct
 */
FILE *check_input(int argc, char *argv[])
{
    FILE *fd;

    if (argc == 1 || argc > 2)
    {
        dprintf(2, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fd = fopen(argv[1], "r");

    if (fd == NULL)
    {
        dprintf(2, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return fd;
}

/**
 * main - Entry point
 *
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    void (*f)(stack_t **stack, unsigned int line_number);
    FILE *fd;
    size_t size = 256;
    ssize_t nlines = 0;
    char *lines[2] = {NULL, NULL};

    fd = check_input(argc, argv);
    start_global(fd);
    nlines = getline(&global.input_buffer, &size, fd);
    while (nlines != -1)
    {
        lines[0] = custom_strtok(global.input_buffer, " \t\n");
        if (lines[0] && lines[0][0] != '#')
        {
            f = get_opcode_function(lines[0]);
            if (!f)
            {
                dprintf(2, "L%u: ", global.curr_line);
                dprintf(2, "unknown instruction %s\n", lines[0]);
                free_global();
                exit(EXIT_FAILURE);
            }
            global.param = custom_strtok(NULL, " \t\n");
            f(&global.head, global.curr_line);
        }
        nlines = getline(&global.input_buffer, &size, fd);
        global.curr_line++;
    }

    free_global();

    return (0);
}
