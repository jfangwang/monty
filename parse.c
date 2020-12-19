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
	char *token, *word = "push";
	int ind, wordlen, toklen, count = 0;

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
	while (fgets(str, MAXCHAR, fp) != NULL)
	{
		/* Will print out each line of file */
		printf("Str is: %s", str);
		token = strtok(str, " ");
		while (token != NULL)
		{
			toklen = 0;
			wordlen = 0;
			ind = 0;
			/* custom len checking for null byte or new line */
			/* len(str) counts newline as character */
			while (*(token + toklen) != '\0' && *(token + toklen) != '\n')
				toklen += 1;
			while (*(word + wordlen) != '\0' && *(word + wordlen) != '\n')
				wordlen += 1;
			if (toklen == wordlen)
			{
				/* This is where we pipe in OP functions and check */
				/* Checks if token and command word is the same */
				while (word[ind] == token[ind] && ind < wordlen)
					ind++;
			}
			if (ind == wordlen)
				count += 1;
			/* Gets next token in line if there is one */
			token = strtok(NULL, " ");
		}
	}
	printf("count: %d\n", count);
	fclose(fp);
	return (0);
}
