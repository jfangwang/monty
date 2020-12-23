#include "monty.h"

/**
 * quickExit-exit, free, close files
 * @head:input
 * @status:exit status
 */
FILE *fp;
void quickExit(stack_t *head, int status)
{
	_free(head);
	fclose(fp);
	exit(status);
}
void quickExitWords(stack_w *head, int status)
{	
	_free_words(head);
	fclose(fp);
	exit(status);
}
void _free(stack_t *head)
{
	if(head == NULL)
		return;
	if ((head)->next != NULL)
		_free((head)->next);
	free(head);
}
void _free_words(stack_w *head)
{
	/*
	if(head == NULL)
		return;
	if ((head)->next != NULL)
		_free_words((head)->next);
		free(head);
	 */
	stack_w *curr = head;
	while ((curr = head) != NULL)
	{
		head = head->next;
		free(curr);
	}
}
