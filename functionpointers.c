#include "monty.h"

void functionpointers(char *token, unsigned int linenum, stack_t **head)
{
	instruction_t array[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		/*{"swap", swap},*/
		/*
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
	int count = 0;
	char t = 't';

	while (array[count].opcode)
	{
		if (sameword(token, array[count].opcode) == t)
		{
			array[count].f(head, linenum);
			return;
		}
		count++;
	}
	if (array[count].opcode == NULL)
		dprintf(STDERR_FILENO, "L%u: unknown\n", linenum);
}
char sameword(char *token, char *cmd)
{
	char t = 't', f = 'f';
	int toklen = 0, cmdlen = 0, sharedLetters = 0;
	
	toklen = 0;
	cmdlen = 0;
	sharedLetters = 0;
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
		return(t);
	else
		return(f);
}
