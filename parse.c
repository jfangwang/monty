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
	void (*push)(stack_t **head, unsigned int line, char *args);
	int linecount, a;
	stack_t *head = NULL;
	stack_w *words = NULL;

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
			/* Separate Push function */
			if (sameword(words->n, "push") == 't')
			{
				if (words->next)
				{
				/* Go through the chars of the next node */
					printf("next word: %s\n", words->next->n);
					pushnum = words->next->n;
					for (a = 0; words->next->n[a] != '\n'; a++)
					{
						if(!isdigit(words->next->n[a]))
						{
							pushnum = "DNE";
							break;
						}
					}
				}
			}
			if (pushnum != "DNE")
				(*push)(&head, linecount, pushnum);
			else
			{
				/* Rest of the commands */
				functionpointers(words->n, linecount, &head);
				words = words->next;
			}
		}
	}
	fclose(fp);
	return (0);
}
