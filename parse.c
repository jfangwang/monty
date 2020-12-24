#include "monty.h"
varlist willy;
#define MAXCHAR 1000
/**
 *main - name may change
 *@argc: arg count
 *@argv: argv array
 *Return: exit failure or an op function
 */
int main(int argc, char *argv[])
{
	char *token, *filename, str[MAXCHAR];
	unsigned int linecount = 0;
	stack_t *head = NULL;
	stack_w *temp = NULL;

	willy.fp = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		quickExit(head, willy.words, EXIT_FAILURE);
	}
	filename = argv[1], willy.fp = fopen(filename, "r"), willy.list = 0;
	if (willy.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		quickExit(head, willy.words, EXIT_FAILURE);
	}
	while (fgets(str, MAXCHAR, willy.fp) != NULL)
	{
		linecount += 1, token = strtok(str, " \n\t");
		while (token != NULL)
		{
			add_string_node(&willy.words, token);
			token = strtok(NULL, " \n\t");
		}
		temp = willy.words;
		while (willy.words != NULL)
		{
			if (sameword(willy.words->n, "push") == 't')
				checkpush(willy.words, &head, linecount);
			else
				funp(willy.words->n, linecount, &head, &willy.words);
			while (willy.words != NULL)
				willy.words = willy.words->next;
		}
		_free_words(temp);
	}
	_free(head);
	fclose(willy.fp);
	return (0);
}
/**
 *checkpush - checks if token is "push" and excutes
 *@words: DLL
 *@head: DLL
 *@linecount: linecount
 *Return: exit failure or void
 */
void checkpush(stack_w *words, stack_t **head, unsigned int linecount)
{
	char *pushnum = "DNE";
	unsigned int flag = 0, a;

	if (words->next)
	{
		words = words->next;
		flag = 0;
		pushnum = words->n;
		for (a = 0; a < 100; a++)
		{
			if (words->n[a] == '\0' || words->n[a] == '\n')
				break;
			if (words->n[a] == '-' && a == 0)
				continue;
			if (!isdigit(words->n[a]))
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			push(head, linecount, pushnum);
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", linecount);
			quickExit(*head, words, EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", linecount);
		quickExit(*head, words, EXIT_FAILURE);
	}
}
