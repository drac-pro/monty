#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO).
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void stack(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;

	carrier.setter = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void queue(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;

	carrier.setter = 1;
}
