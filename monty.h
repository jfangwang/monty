#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_a
{
	char *n;
	struct stack_a *prev;
	struct stack_a *next;
} stack_w;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern FILE *fp;
void swap(stack_t **head, unsigned int line);
void reverse(stack_w **h);
void functionpointers(char *token, unsigned int linenum, stack_t **head);
void add_node(stack_t **head, int n);
void add_string_node(stack_w **head, char* n);
char sameword(char *token, char *cmd);
void delete_node(stack_t **head, unsigned int index);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line);
size_t print_node(const stack_t *h);
void push(stack_t **head, unsigned int line, char *args);
void quickExit(stack_t *head, int status);
void _free(stack_t *head, int status);
#endif
