#include "monty.h"

/**
 * push - adds an element to the stack
 * @head: double pointer to the first node
 * @line_number: value of new node
 * @args: input from file
 * Return: nothing
 */
#define STDERR_FILENO
void push(stack_t **head, unsigned int line_number, char **args)
{
	stack_t *new;
	int print = 0;

	if (head == NULL)
		return;
	if (args[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
	}

	new = malloc(sizeof(stack_t))
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
	}

	num = atoi(args[1]);
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		*head->prev = new;
	*head = new;
}
