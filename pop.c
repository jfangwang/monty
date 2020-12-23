#include "monty.h"

/**
 * pop-remove top node
 * @line:line args came from
 * @head:input
 */
void pop(stack_t **head, unsigned int line)
{
	stack_t *new = *head;

	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line);
		quickExit(*head, willy.words, EXIT_FAILURE);
	}

	*head = new->next;
	free(new);

	if (*head != NULL)
		(*head)->prev = NULL;
}
