#include "monty.h"
/**
 **add_dnodeint - Write a function that adds a new node at the
 *beginning of double linked list
 *@head: head
 *@n: number
 *Return: void
 **/

void add_node(stack_t **head, const int n)
{
        stack_t *new, *big_head;

        if (head == NULL)
                printf("#1 Head is null from add node\n");
        big_head = *head;
        new = malloc(sizeof(stack_t));
        if (new == NULL)
                printf("#2 Head is null from add node\n");
        new->n = n;
        new->prev = NULL;
        new->next = *head;
        if (*head != NULL)
                big_head->prev = new;
        *head = new;
        return;
}
void delete_node(stack_t **head, unsigned int index)
{
	stack_t *list = *head;
	unsigned int count;

	if (!*head || !head)
	{
		printf("head is null");
		return;
	}
	for (count = 0; list != NULL; count++)
	{
		if (count== index)
		{
			if (list->prev && list->next)
				list->prev->next = list->next;
			if (list->prev && list->next == NULL)
				list->prev = NULL;
			if (list->prev == NULL && list->next)
				*head = list->next;
			free(list);
			return;
		}
		list = list->next;
	}
}
