#include "monty.h"

/**
 * pint-print first int in stack
 * Return: void
 * @line:line args come from
 * @head:input
 */
void pint(unsigned int line, stack_t **head)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		/*insert exit here*/
	}

	printf("%d\n", (*stack)->n);
}
