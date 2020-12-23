#include "monty.h"

#define MAXCHAR 1000
/**
 *main - name may change
 *@argc: arg count
 *@argv: argv array
 *Return: exit failure or an op function
 */
/**
* This code fails:
* Negative Numbers
* Empty New Lines
* Blank lines with more spaces
*/
FILE *fp;
int main(int argc, char *argv[])
{
	char *token, *filename, str[MAXCHAR];
	unsigned int linecount = 0;
	unsigned int flag = 0, a;
	char *pushnum = "DNE";
	stack_t *head = NULL;
	stack_w *words = NULL;
	stack_w *temp = NULL;
	fp = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		quickExit(head, words, EXIT_FAILURE);
	}
	filename = argv[1];
	fp = fopen(filename, "r");
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
			/*add to words DLL */
			add_string_node(&words, token);
			token = strtok(NULL, " \n\t");
		}
		/* Iterate through words DLL */
		temp = words;
		while (words != NULL)
		{
			if (sameword(words->n,"push") == 't')
			{
				if (words->next)
				{
					words = words->next;
					flag = 0;
					pushnum = words->n;
					for(a = 0; a < 100; a++)
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
						push(&head, linecount, pushnum);
						/*
						_push(head, linecount, pushnum);
						(*push)(&head, linecount, pushnum);
						*/
					else
					{
						fprintf(stderr, "L%u: usage: push integer\n", linecount);
						quickExit(head, words, EXIT_FAILURE);
					}
				}
				else
				{
					fprintf(stderr, "L%u: usage: push integer\n", linecount);
					quickExit(head, words, EXIT_FAILURE);
				}
			}
			else
				funp(words->n, linecount, &head, &words);
			while(words != NULL)
				words = words->next;
		}
		/*free_temp(words, head, linecount);*/
		_free_words(temp);
	}
	_free(head);
	fclose(fp);
	return (0);
}
void _push(stack_t *head, unsigned int linecount, char *pushnum)
{
	(*push)(&head, linecount, pushnum);
}
void free_temp (stack_w *words, stack_t *head, unsigned int linecount)
{
	unsigned int a, flag = 0;
	char *pushnum = "DNE";

	while (words != NULL)
	{
		if (sameword(words->n,"push") == 't')
		{
			if (words->next)
			{
				words = words->next;
				flag = 0;
				pushnum = words->n;
				for(a = 0; a < 100; a++)
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
					(*push)(&head, linecount, pushnum);
				else
				{
					fprintf(stderr, "L%u: usage: push integer\n", linecount);
					quickExit(head, words, EXIT_FAILURE);
				}
			}
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", linecount);
				quickExit(head, words, EXIT_FAILURE);
			}
		}
		else
			funp(words->n, linecount, &head, &words);
		while(words != NULL)
			words = words->next;
	}
}
