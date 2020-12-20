void (*f)(stack_t **stack, unsigned int line_number)
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
		{NULL, NULL}
	};
	int count = 0;

	while (*(array + count)->opcode)
	{
		if (*(array + i)->letter == s)
			break;
		count++;
	}
	return (*(array + i)->f);
}
