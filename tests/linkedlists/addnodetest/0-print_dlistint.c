#include "../../../monty.h"
/**
 *print_dlistint - Write a function that prints all
 *the elements of a dlistint_t list.
 *@h: a variable
 *Return: 0
 **/

size_t print_dlistint(const stack_t *h)
{
	int count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		count += 1;
		h = h->next;
	}
	return (count);

}
