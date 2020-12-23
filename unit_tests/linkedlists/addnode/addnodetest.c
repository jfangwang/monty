#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	stack_t *head;

	head = NULL;
	add_node(&head, 0);
	add_node(&head, 1);
	add_node(&head, 2);
	add_node(&head, 3);
	add_node(&head, 4);
	add_node(&head, 98);
	add_node(&head, 402);
	add_node(&head, 1024);
	print_node(head);
	_free(head);
	return (EXIT_SUCCESS);
}
