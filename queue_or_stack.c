#include "monty.h"
/**
 * queue- switches to queue
 * @head: head of list
 * @line:line args came from
 * Return: void
 */
void queue(stack_t **head, unsigned int line)
{
	(void)line;
	if (willy.list == 0)
	{
		willy.list = 1;
		reverse_num(head);
		reverse_num(head);
	}
}
/**
 * stack- switches to stack
 * @head: head of list
 * @line:line args came from
 * Return: void
 */
void stack(stack_t **head, unsigned int line)
{
	(void)line;
	if (willy.list == 1)
	{
		willy.list = 0;
		reverse_num(head);
		reverse_num(head);
	}
}
/**
 * reverse_num- reverses a DLL
 * @h: head of list
 * Return: void
 */
void reverse_num(stack_t **h)
{
	stack_t *prev = NULL;
	stack_t *current = *h;
	stack_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*h = prev;
}
