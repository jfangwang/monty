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
	/*Filename will be argv, max num of chars */
	char *filename, str[MAXCHAR];
	/* Given Command */
	char *token;
	char *word;
	char *word2 = "push\n";
	int ind, wordlen, toklen, linecount, count = 0;
	/* Stack DLL */
	stack_t *head;
	head = NULL;	

	/* num of args */
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	filename = argv[1];
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	linecount = 0;
	while (fgets(str, MAXCHAR, fp) != NULL)
	{
		/* Will print out each line of file */
		linecount += 1;
		//printf("Line: %d Str is: %s\n", linecount, str);
		token = strtok(str, " ");
		while (token != NULL)
		{
			toklen = 0;
			wordlen = 0;
			ind = 0;
			/* custom len checking for null byte or new line */
			/* len(str) counts newline as character */
				/* This is where we pipe in OP functions and check */
				/* Checks if token and command word is the same */
				/*
				functionpointers(char *word, unsigned int linenum, stack_t **head)
				while (word[ind] == token[ind] && ind < wordlen)
					ind++;
				*/
			//printf("From parse %s\n", token);
			functionpointers(token, linecount, &head);
			/* Gets next token in line if there is one */
			token = strtok(NULL, " ");
		}
	}
	fclose(fp);
	return (0);
}
