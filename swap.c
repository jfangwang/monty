#include "monty.h"

/**
 * swap-swaps first two nodes
 * @line:line arguments came from
 * @head:input
 */
void swap(stack_t **head, unsigned int line)
{
	stack_t *temp;
	stack_w **words = NULL;

	if (head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line);
		quickExit(*head, *words, EXIT_FAILURE);
	}
	temp = (*head);
	(*head) = temp->next;
	temp->prev = (*head);
	temp->next = (*head)->next;
	(*head)->prev = NULL;
	(*head)->next = temp;
	if ((*head)->next != NULL)
		(*head)->next->prev = temp;
}
