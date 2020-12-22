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
	FILE *fp;
	char *token, *filename, str[MAXCHAR];
	void (*pushfunc)(stack_t **head, unsigned int line, char *args) = &push;
	unsigned int linecount, a, flag = 0;
	stack_t *head = NULL;
	stack_w *words = NULL;
	char *pushnum = "DNE";

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	linecount = 0;
	while (fgets(str, MAXCHAR, fp) != NULL)
	{
		linecount += 1;
		token = strtok(str, " ");
		while (token != NULL)
		{
			/*add to words DLL */
			add_string_node(&words, token);
			token = strtok(NULL, " ");
		}
		reverse(&words);
		/* Iterate through words DLL */
		while (words != NULL)
		{
			if (sameword(words->n,"push") == 't' && words->next)
			{
				words = words->next;
				flag = 0;
				pushnum = words->n;
				for(a = 0; a < 100; a++)
				{
					if (words->n[a] == '\0' || words->n[a] == '\n')
						break;
					if (!isdigit(words->n[a]))
						flag = 1;
				}
				if (flag == 0)
					(*push)(&head, linecount, pushnum);
			}
			else
				functionpointers(words->n, linecount, &head);
			words = words->next;
		}
		free(words);
	}
	fclose(fp);
	return (0);
}
