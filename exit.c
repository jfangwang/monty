#include "monty.h"

/**
 * quickExit-exit, free, close files
 * @head:input
 * @status:exit status
 */
void quickExit(stack_t *head, stack_w *words, int status)
{
	if (head != NULL)
		_free(head);
	if (words != NULL)
		_free_words(words);
	if (fp != NULL)
		fclose(fp);
	exit(status);
}
void quickExitWords(stack_w *head, stack_w *words, int status)
{
	if (head != NULL)
		_free_words(head);
	if (words != NULL)
		_free_words(words);
	if (fp != NULL)
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
	stack_w *temp;

	temp = head;
	while(head)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
