#include "monty.h"

/**
 * push - adds an element to the stack
 * @head: head of list
 * @line:line args came from
 * @args: input from file
 * Return: void
 */
void push(stack_t **head, unsigned int line, char **args)
{
	stack_t *new;
	/*
	int num;
	*/
	if (head == NULL)
		return;
	if (args[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
	}
	/*
	num = atoi(args[1]);
	*/
	new->prev = NULL;
	new->next = *head;
	/*
	if (*head != NULL)
		*head->prev = new;
	*/
	*head = new;
}
