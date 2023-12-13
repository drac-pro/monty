#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct carrier_s - carries variables between functions in the programe
 * @file: File pointer to the monty file
 * @line: pointer to a string found on a line in file
 * @arg: opcode argument
 *
 * Description: carry values through functions in the programe
 */
typedef struct carrier_s
{
	FILE *file;
	char *line;
	char *arg;
} carrier_t;
extern carrier_t carrier;

void exec(stack_t **top, unsigned int line_number);

void free_stack(stack_t *top);
void addnode(stack_t **top, int n);

void push(stack_t **top, unsigned int line_number);
void pall(stack_t **top, unsigned int line_number);
void pint(stack_t **top, unsigned int line_number);
void pop(stack_t **top, unsigned int line_number);
void swap(stack_t **top, unsigned int line_number);
void add(stack_t **top, unsigned int line_number);
void nop(stack_t **top, unsigned int line_number);

#endif /*MONTY_H*/
