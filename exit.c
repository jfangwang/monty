#include "monty.h"

/**
 * quickExit-exit, free, close files
 * @head:input
 * @status:exit status
 */
void quickExit(stack_t *head, int status)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
	fclose(fp);
	exit(status);
}
