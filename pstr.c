#include "monty.h"

/**
 * pall-print all values on the stack
 * @head:head of list
 * @line_number: line num
 * Return:void
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *c = *head;
	(void)line_number;

	if (c == NULL)
		putchar('\n');
	while (c != NULL || c->n != '0' || (c->n < 256 && c->n > -1))
	{
		putchar(c->n);
		c = c->next;
	}
}
