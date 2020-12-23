#include "monty.h"

/**
 * quickExit - exit, free, close files
 * @head:DLL
 * @words: DLL
 * @status:exit status
 * Return: void
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
/**
 * _free - exit, free, close files
 * @head:DLL
 * Return: void
 */
void _free(stack_t *head)
{
	if (head == NULL)
		return;
	if ((head)->next != NULL)
		_free((head)->next);
	free(head);
}
/**
 * _free_words - exit, free, close files
 * @head:DLL
 * Return: void
 */
void _free_words(stack_w *head)
{
	stack_w *temp;

	temp = head;
	while (head)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
