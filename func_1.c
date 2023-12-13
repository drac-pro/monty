#include "monty.h"

/**
 * push - pushes an element onto the stack
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void push(stack_t **top, unsigned int line_number)
{
	int n, i = 0;

	if (carrier.arg)
	{
		if (carrier.arg[0] == '-')
			i++;
		while (carrier.arg[i] != '\0')
		{
		if (carrier.arg[i] < 48 || carrier.arg[i] > 57)
		{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(carrier.file);
			free(carrier.line);
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
		i++;
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	n = atoi(carrier.arg);
	addnode(top, n);
}

/**
 * pall - print all values on the stack starting from the top
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	(void)line_number;

	if (!current)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - print the value at the top of the stack
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void pint(stack_t **top, unsigned int line_number)
{
	if (!(*top))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}

/**
 * pop - removes the value at the top of the stack
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;

	if (!current)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	*top = (*top)->next;
	if (*top)
		(*top)->prev = NULL;
	free(current);
}

/**
 * swap - swap the top two elements of the stack
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int temp;

	if (!current || (current && !current->next))
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	temp = current->n;
	current->n = (current->next)->n;
	(current->next)->n = temp;
}
