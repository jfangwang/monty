#include "monty.h"

void functionpointers(char *token, unsigned int linenum, stack_t **head)
{
	instruction_t array[] = {
		/*{"push", push},*/
		/*
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"#", comment},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		*/
		{NULL, NULL}
	};
	char *cmd;
	int count = 0, toklen = 0, cmdlen = 0, sharedLetters = 0;

	while (array[count].opcode)
	{
		toklen = 0;
		cmdlen = 0;
		sharedLetters = 0;
		cmd = array[count].opcode;
		while (*(token + toklen) != '\0' && *(token + toklen) != '\n')
			toklen += 1;
		while (cmd[cmdlen] != '\0' && cmd[cmdlen] != '\n')
			cmdlen += 1;
		if (toklen == cmdlen)
		{
			while (cmd[sharedLetters] == token[sharedLetters] && sharedLetters < cmdlen)
					sharedLetters++;
		}
		if (sharedLetters == cmdlen)
		{
			array[count].f(head, linenum);
			return;
		}
		else
			count++;
	}
	if (array[count].opcode == NULL)
	{
		printf("Error from functionpointers\n");
		free(head);
		exit(EXIT_FAILURE);
	}
}
