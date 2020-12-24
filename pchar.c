#include "monty.h"

/**
 * pchar-remove top node
 * @line:line args came from
 * @head:input
 */
void pchar(stack_t **head, unsigned int line)
{
	if ((*head) == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line);
		quickExit(*head, willy.words, EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 255)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", line);
		quickExit(*head, willy.words, EXIT_FAILURE);
	}

	putchar((*head)->n);
	putchar('\n');
}
