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
	int linecount;
	stack_t *head = NULL;

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
			functionpointers(token, linecount, &head);
			token = strtok(NULL, " ");
		}
	}
	fclose(fp);
	return (0);
}
