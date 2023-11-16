#include "monty.h"

node *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openfile(argv[1]);
	freenodes();
	return (0);
}

/**
 * createnode - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon success a pointer to the node. Otherwise NULL.
 */
node *createnode(int n)
{
	node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
    {
        exit(EXIT_FAILURE);
    }
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->val = n;
    return (newnode);
}

/**
 * freenodes - Frees nodes in the stack.
 */
void freenodes(void)
{
	node *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * addToQueue - Adds a node to the queue.
 * @newnode: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void addToQueue(node **newnode, __attribute__((unused))unsigned int ln)
{
	node *tmp;

	if (newnode == NULL || *newnode == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *newnode;
		return;
	}

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *newnode;
	(*newnode)->prev = tmp;
}
