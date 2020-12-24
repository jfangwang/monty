#include "monty.h"

/**
 * pstr-print all values on the stack
 * @head:head of list
 * @line_number: line num
 * Return:void
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *c = *head;
	(void)line_number;

	if (c == NULL)
	{
		putchar('\n');
		return;
	}
	while (c != NULL)
	{
		if (c->n > 0 && c->n < 128)
			putchar(c->n);
		else
			break;
		c = c->next;
	}
	putchar('\n');
}
