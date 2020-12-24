#include "monty.h"

/**
* funp - points to a function
* @token: token
* @linenum: linenum
* @head: head DLL
* @words: words DLL
* Return: void
 */
void funp(char *token, unsigned int linenum, stack_t **head, stack_w **words)
{
	instruction_t array[] = {
		{"#", comment}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		/*
		 *{"pstr", pstr},
		 *{"rotl", rotl},
		 *{"rotr", rotr},
		 *{"stack", stack},
		 *{"queue", queue},
		 */
		{NULL, NULL}
	};
	int count = 0;
	char t = 't';
	char *h = "#j";

	if (token[0] == h[0])
		array[0].f(head, linenum);
	else
	{
		while (array[count].opcode)
		{
			if (sameword(token, array[count].opcode) == t)
			{
				array[count].f(head, linenum);
				return;
			}
			count++;
		}
	}
	if (array[count].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", linenum, token);
		quickExit(*head, *words, EXIT_FAILURE);
	}
}
/**
 * sameword - checks if token and cmd is the same word
 * @token: token
 * @cmd: command
 * Return: void
 */
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
		return (t);
	else
		return (f);
}
/**
 *reverse - reverses a list
 *@h: head
 *Return: void
 */
void reverse(stack_w **h)
{
	stack_w *prev = NULL;
	stack_w *current = *h;
	stack_w *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*h = prev;
	free(prev);
}
