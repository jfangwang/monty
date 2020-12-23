#include "monty.h"

/**
 * pint-print first int in stack
 * Return: void
 * @line:line args come from
 * @head:input
 */
void pint(stack_t **head, unsigned int line)
{
	stack_w **words = NULL;

	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line);
		quickExit(*head, *words, EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
