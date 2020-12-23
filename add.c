#include "monty.h"

/**
 * add-adds two nodes
 * @head:input
 * @line:line args came from
 */
void add(stack_t **head, unsigned int line)
{
	stack_t *temp = *head, *next;
	stack_w **words = NULL;

	if (head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line);
		quickExit(*head, willy.words, EXIT_FAILURE);
	}

	next = temp->next;
	next->n += temp->n;
	free(temp);
	next->prev = NULL;
	*head = next;
}
