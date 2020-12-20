#include "monty.h"

void functionpointers(char *word, unsigned int linenum, stack_t **head)
{
	/*
	   typedef struct instruction_s
	   {
	   char *opcode;
	   void (*f)(stack_t **stack, unsigned int line_number);
	   } instruction_t;
	 */
	instruction_t array[] = {
		/*
		{"push", push},
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
		{"dumbfunc", dumbfunc},
		{NULL, NULL}
	};
	char *dumbfunc = "dumbfunc";
	int count = 0;

	while (array[count].opcode)
	{
		if (array[count].opcode == dumbfunc)
		{
			array[count].f(head, linenum);
			return;
		}
		else
			count++;
	}
	if (array[count].opcode == NULL)
	{
		printf("Error from functionpointers");
		free(head);
		exit(EXIT_FAILURE);
	}
}
