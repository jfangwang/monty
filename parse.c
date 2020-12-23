#include "monty.h"

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
	stack_w *words = NULL, *temp = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		quickExit(head, words, EXIT_FAILURE);
	}
	filename = argv[1], fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		quickExit(head, words, EXIT_FAILURE);
	}
	while (fgets(str, MAXCHAR, fp) != NULL)
	{
		linecount += 1;
		token = strtok(str, " \n\t");
		while (token != NULL)
		{
			add_string_node(&words, token);
			token = strtok(NULL, " \n\t");
		}
		temp = words;
		while (words != NULL)
		{
			if (sameword(words->n, "push") == 't')
				checkpush(words, &head, linecount);
			else
				funp(words->n, linecount, &head, &words);
			while (words != NULL)
				words = words->next;
		}
		_free_words(temp);
	}
	_free(head);
	fclose(fp);
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
