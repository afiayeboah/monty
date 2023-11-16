#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * global - Global data for program functions
 * @is_stack: Flag for stack (1) or queue (0) mode
 * @curr_line: Pointer to current line content
 * @param: Pointer to second parameter in the line
 * @head: Pointer to doubly linked list node
 * @file: File descriptor
 * @input_buffer: Pointer to input text buffer
 *
 * Description: Holds global data for Holberton project functions involving
 *              stack, queue, LIFO, and FIFO operations.
 */
typedef struct global
{
	int is_stack;
	char *curr_line;
	char *param;
	stack_t *head;
	int file;
	char *input_buffer;
} global_t;
extern global_t global;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main */
void free_global(void);

/* imported functions */
int find_char(char *s, char c);
char *custom_strtok(char *s, char *delimiters);
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *custom_calloc(unsigned int nmemb, unsigned int size);
int custom_strcmp(char *s1, char *s2);

/* Doubly linked list functions */
stack_t *add_node_to_end(stack_t **head, const int n);
stack_t *add_node_to_start(stack_t **head, const int n);
void free_doubly_list(stack_t *head);

/* Opcode instructions */
void push_stack(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **doubly, unsigned int cline);
void pint_str(stack_t **stack, unsigned int line_number);
void pop_stack(stack_t **doubly, unsigned int cline);
void swap_stack(stack_t **doubly, unsigned int cline);
void add_nodes(stack_t **doubly, unsigned int cline);
void queue_mode(stack_t **doubly, unsigned int cline);
void stack_mode(stack_t **doubly, unsigned int cline);
void no_operation(stack_t **doubly, unsigned int cline);
void subtract_nodes(stack_t **doubly, unsigned int cline);
void divide_nodes(stack_t **doubly, unsigned int cline);
void multiply_nodes(stack_t **doubly, unsigned int cline);
void modulo_nodes(stack_t **doubly, unsigned int cline);
void print_char(stack_t **doubly, unsigned int cline);
void print_str(stack_t **doubly, unsigned int cline);
void rotate_left(stack_t **doubly, unsigned int cline);
void rotate_right(stack_t **doubly, unsigned int cline);

/* Get function */
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number);
#endif
