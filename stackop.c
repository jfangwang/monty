#include "monty.h"
/**
 **add_dnodeint - Write a function that adds a new node at the
 *beginning of double linked list
 *@head: head
 *@n: number
 *Return: void
 **/

/* EXAMPLE of STACK
	[ 1 ]
	[ 2, 1 ]
	[ 3. 2. 1 ]
	[ Top ... Bottom ]
*/
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
/*This may be useless*/
void delete_node(stack_t **head, unsigned int index)
{
	stack_t *next, *prev;
	stack_t *cur = (*head);
	unsigned int count = 0;

	if (*head == NULL || head == NULL)
	{
		/*printf("head is null");*/
		return;
	}
	for (count = 0; cur != NULL; count++)
	{

		if (count == index)
		{
			prev = cur->prev;
			next = cur->next;
			/*MIDDLE*/
			if (prev && next){
				/*printf("index: %d, prev: %d, cur: %d, next: %d\n", count, prev->n, list->n, next->n);*/
				prev->next = next;
				next->prev = prev;
				free(cur);
			}
			/*FIRST*/
			else if (prev == NULL && next){
				/*printf("index: %d, prev: NA, cur: %d, next: %d\n",index, list->n, list->next->n);*/
				cur->next = next;
				next->prev = NULL;
				(*head) = next;;
				free(cur);
			}
			/*LAST*/
			else if (next == NULL && prev){
				/*printf("index: %d, prev: NA, cur: %d, next: %d\n",index, cur->n, next->n);*/
				prev->next = NULL;
				free(next);
			}
			/*Only One*/
			else if (next == NULL && prev == NULL){
				/*printf("index: %d, prev: NA, cur: %d, next: NA\n", index, list->n);*/
				free(cur);
				(*head) = NULL;
			}
			return;
		}
		cur = cur->next;
	}
}
