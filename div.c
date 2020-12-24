#include "monty.h"

/**
 * _div - 2nd / 1st = 2nd
 * @head:input
 * @line:line arguments came from
 * Return: void
 */
void _div(stack_t **head, unsigned int line)
{
	stack_t *temp;

	if ((*head) == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line);
		quickExit(*head, willy.words, EXIT_FAILURE);
	}
	if ((*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line);
		quickExit(*head, willy.words, EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line);
		quickExit(*head, willy.words, EXIT_FAILURE);
	}
	temp = (*head);
	(*head) = (*head)->next;
	(*head)->n = ((*head)->n) / (temp->n);
	free(temp);
}
