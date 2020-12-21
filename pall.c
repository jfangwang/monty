#include "monty.h"

/**
 * pall-print all values on the stack
 * Return:void
 * @head:head of list
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void)line_number;

	if (current == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
