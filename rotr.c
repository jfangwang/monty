#include "monty.h"
/**
 *rotr - prints all nodes
 *@head: head
 *@line_number: linue num
 *Return: size_t
 **/
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *next, *temp = (*head);
	(void)line_number;

	if (temp == NULL)
		return;
	if (temp->next == NULL)
		return;
	next = (*head)->next;
	while (next->next)
	{
		next = next->next;
		temp = temp->next;
	}
	temp->next = NULL;
	next->next = (*head);
	next->prev = NULL;
	(*head)->prev = next;
	(*head) = next;
}
