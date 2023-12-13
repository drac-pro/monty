#include "monty.h"

/**
 * add - adds the top two elements of the stack and save it to the 2nd element
 *	the first element is deleted
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void add(stack_t **top, unsigned int line_number)
{
	int sum;
	stack_t *current = *top;

	if (!current || (current && !current->next))
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	sum = current->n + (current->next)->n;
	current = current->next;
	current->n = sum;
	pop(top, line_number);
}

/**
 * nop - does nothing
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}
