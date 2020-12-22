#include "monty.h"

#define MAXCHAR 1000
/**
*main - name may change
*@argc: arg count
*@argv: argv array
*Return: exit failure or an op function
*/
FILE *fp;
int main(int argc, char *argv[])
{
	char *token, *filename, str[MAXCHAR];
	unsigned int linecount = 0, a, flag = 0;
	stack_t *head = NULL;
	stack_w *words = NULL;
	char *pushnum = "DNE";

	if (argc != 2)
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
	filename = argv[1];
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
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
				if (words->next)
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
					else
						dprintf(STDERR_FILENO, "L%u: usage: push integer\n", linecount);
				}
				else
					dprintf(STDERR_FILENO, "L%u: usage: push integer\n", linecount);
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
