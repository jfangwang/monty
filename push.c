#include "monty.h"

/**
 * push - adds an element to the stack
 * @head: head of list
 * @line:line args came from
 * @args: input from file
 * Return: void
 */
void push(stack_t **head, unsigned int line, char *args)
{
	stack_t *new;
	int num;

	(void)line;
	if (head == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
	num = atoi(args);
	new->n = num;
	new->next = *head;
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	*head = new;
}
