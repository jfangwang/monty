#include "monty.h"
/**
 *print_dlistint - Write a function that prints all
 *the elements of a dlistint_t list.
 *@h: a variable
 *Return: 0
 **/

size_t print_node(const stack_t *h)
{
	int count = 0;

	if (h == NULL)
		
	while (h)
	{
		printf("%d\n", h->n);
		count += 1;
		h = h->next;
	}
	return (count);

}
