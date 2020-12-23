#include "monty.h"
/*
 *EXAMPLE of STACK
 *	[ 1 ]
 *	[ 2, 1 ]
 *	[ 3. 2. 1 ]
 *	[ Top ... Bottom ]
 */

/**
 *add_string_node - adds a new node at the
 *beginning of double linked list
 *@head: head
 *@n: number
 *Return: void
 **/
void add_string_node(stack_w **head, char *n)
{
	stack_w *new, *big_head;

	big_head = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}	
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		big_head->prev = new;
	*head = new;
}
/**
 *add_node - adds a new node at the
 *beginning of double linked list
 *@head: head
 *@n: number
 *Return: void
 **/
void add_node(stack_t **head, int n)
{
	stack_t *new, *big_head;

	big_head = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		quickExit(*head, EXIT_FAILURE);
	}	
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		big_head->prev = new;
	*head = new;
}

/**
 *print_node - prints all nodes
 *@h: head
 *Return: size_t
 **/
size_t print_node(const stack_t *h)
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
/**
 *delete_node - name may change
 *@head: head
 *@index: num
 *Return: void
 */
void delete_node(stack_t **head, unsigned int index)
{
	stack_t *next, *prev;
	stack_t *cur = (*head);
	unsigned int count = 0;

	if (*head == NULL || head == NULL)
	{
		printf("head is null");
		return;
	}
	for (count = 0; cur != NULL; count++)
	{
		if (count == index)
		{
			prev = cur->prev;
			next = cur->next;
			if (prev && next)
			{
				prev->next = next;
				next->prev = prev;
			}
			else if (prev == NULL && next)
			{
				cur->next = next;
				next->prev = NULL;
				*head = next;
			}
			else if (next == NULL && prev)
			{
				prev->next = NULL;
				free(next);
			}
			else if (next == NULL && prev == NULL)
			{
				(*head) = NULL;
			}
			free(cur);
		}
		cur = cur->next;
	}
}
void reverse(stack_w **h)
{
    stack_w *prev = NULL;
    stack_w *current = *h;
    stack_w *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
	prev = current;
	current = next;
    }
    *h = prev;
}
