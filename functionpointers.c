#include "monty.h"

void functionpointers(char *token, unsigned int linenum, stack_t **head)
{
	/*
	   typedef struct instruction_s
	   {
	   char *opcode;
	   void (*f)(stack_t **stack, unsigned int line_number);
	   } instruction_t;
	 */
	instruction_t array[] = {
		{"push", push},
		/*
		{"pall", pall},
		*/
		{"pint", pint},
		/*
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
	char *command, *dumbfunc = "dumbfunc";
	int count = 0;
	int toklen = 0;
	int commandlen = 0;
	int sharedLetters = 0;

	while (array[count].opcode)
	{
		toklen = 0;
		commandlen = 0;
		sharedLetters = 0;
		command = array[count].opcode;
		/* Checks the len of token and command */
		while (*(token + toklen) != '\0' && *(token + toklen) != '\n')
			toklen += 1;
		while (command[commandlen] != '\0' && command[commandlen] != '\n')
			commandlen += 1;
		if (toklen == commandlen)
		{
			/* Checks if they have the same letters */
			while (command[sharedLetters] == token[sharedLetters] && sharedLetters < commandlen)
					sharedLetters++;
		}
		/* Command == Token if sharedLetters is the commandlen */
		if (sharedLetters == commandlen)
		{
			array[count].f(head, linenum);
			return;
		}
		else
			count++;
	}
	/* Will create a custom error function if command is not found */
	if (array[count].opcode == NULL)
	{
		printf("Error from functionpointers\n");
		free(head);
		exit(EXIT_FAILURE);
	}
}
