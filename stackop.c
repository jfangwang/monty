#include "monty.h"
/**
 **add_dnodeint - Write a function that adds a new node at the beginning of a d
 *listint_t list.
 *@head: a variable
 *@n: a variable
 *Return: 0
 **/

stack_t *add_node(stack_t **head, const int n)
{
        stack_t *new, *big_head;

        if (head == NULL)
                return (NULL);
        big_head = *head;
        new = malloc(sizeof(stack_t));
        if (new == NULL)
                return (NULL);
        new->n = n;
        new->prev = NULL;
        new->next = *head;
        if (*head != NULL)
                big_head->prev = new;
        *head = new;
        return (new);
}
