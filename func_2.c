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

/**
 * sub - subtract the top element of the stack from the second and the result
 *	is stored in the second top element and the first element is deleted
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void sub(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int diff;

	if (!current || (current && !current->next))
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	diff = (current->next)->n - current->n;
	(current->next)->n = diff;
	pop(top, line_number);
}

/**
 * div_f - divides the second top element of the stack by the top element and
 *	the result is stored in the second top element and the first element
 *	is pop
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void div_f(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int result;

	if (!current || (current && !current->next))
	{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	result = (current->next)->n / current->n;
	(current->next)->n = result;
	pop(top, line_number);
}

/**
 * mul -  multiplies the second top element of the stack with the top element
 *	of the stack the result is stored int the second top element and the
 *	top is pop
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void mul(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int product;

	if (!current || (current && !current->next))
	{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	product = (current->next)->n * current->n;
	(current->next)->n = product;
	pop(top, line_number);
}
