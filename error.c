#include "monty.h"

void error(int error, unsigned int line)
{
	switch (error)
	{
		/* No argument or not an int */
		case 1: dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
			break;
		/* Invalid command */
		case 2: dprintf(STDERR_FILENO, "L%u: unknown\n", line);
			break;
		case 3: dprintf(STDERR_FILENO, "USAGE: monty file\n");
			break;
		default: printf("error num does not exist\n");
	}
	exit(EXIT_FAILURE);	
}
