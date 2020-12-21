#include "monty.h"

/**
 * push - adds an element to the stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	char *op;
	int num;

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, DELIMS);
	if (op == NULL || stack == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(op, line_number);
	new->n = num;
	new->prev = NULL;
	new->next = *stack;
	if (new->next != NULL)
		(new->next)->prev = new;
	*stack = new;
}
