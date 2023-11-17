#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct node - doubly linked list representation of a stack (or queue)
 * @val: integer value
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct node
{
    int val;
    struct node *prev;
    struct node *next;
} node;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle opcode
 *
 * Description: opcode and their function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(node **stack, unsigned int line);
} instruction_t;

extern node *head;
typedef void (*opfunc)(node **, unsigned int);

/*file operations*/
void openfile(char *fname);
int parseline(char *buf, int line, int format);
void readfile(FILE *);
int charscount(FILE *);
void findfunc(char *, char *, int, int);

/*Stack operations*/
node *createnode(int n);
void freenodes(void);
void printstack(node **, unsigned int);
void addtostack(node **, unsigned int);
void addtoqueue(node **, unsigned int);

void callfunc(opfunc, char *, char *, int, int);

void printtop(node **, unsigned int);
void poptop(node **, unsigned int);
void nop(node **, unsigned int);
void swapnodes(node **, unsigned int);

/*Math operations with nodes*/
void addnodes(node **, unsigned int);
void subnodes(node **, unsigned int);
void divnodes(node **, unsigned int);
void mulnodes(node **, unsigned int);
void modnodes(node **, unsigned int);

/*String operations*/
void printchar(node **, unsigned int);
void printstr(node **, unsigned int);
void rotleft(node **, unsigned int);

/*Error handling*/
void handleerror(int errorcode, ...);
void moreerror(int errorcode, ...);
void str_error(int errorcode, ...);
void rotright(node **, unsigned int);

#endif
