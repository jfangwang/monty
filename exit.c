#include "monty.h"

/**
 * quickExit-exit, free, close files
 * @head:input
 * @status:exit status
 */
FILE *fp;
void quickExit(stack_t *head, int status)
{	
	_free(head, status);
	fclose(fp);
	exit(status);
}
void _free(stack_t *head, int status)
{
	if(head == NULL)
		return;
	if ((head)->next != NULL)
		_free((head)->next, status);
	free(head);
}
