#include "monty.h"

/**
 * mod - computes the remainder of the division of the second top element of
 *	the stack by the top element of the stack the result is stored in the
 *	second top element of the stack, and the top is pop
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void mod(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int remainder;

	if (!current || (current && !current->next))
	{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	remainder = (current->next)->n % current->n;
	(current->next)->n = remainder;
	pop(top, line_number);
}

/**
 * pchar - prints the char at the top of the stack
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void pchar(stack_t **top, unsigned int line_number)
{
	if (!(*top))
	{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n < 0 || (*top)->n > 127)
	{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*top)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void pstr(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	(void)line_number;

	while (current && (current->n > 0 && current->n < 128))
	{
		printf("%c", current->n);
		current = current->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void rotl(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top, *next = (*top)->next;
	(void)line_number;

	if (!current)
		return;
	current->next = NULL;
	current->prev = next;
	while (next)
	{
		next->prev = next->next;
		next->next = current;
		current = next;
		next = next->prev;
	}
	*top = current;
}

/**
 * rotr - rotates the stack to the bottom The last element of the stack becomes
 *	the top element of the stack
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void rotr(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	(void)line_number;

	if (!current || !current->next)
		return;
	while (current->next)
		current = current->next;
	current->next = *top;
	(current->prev)->next = NULL;
	current->prev = NULL;
	(*top)->prev = current;
	*top = current;
}
