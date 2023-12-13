#include "monty.h"

/**
 * addnode - adds a new node at the head of a doubly linked list
 *
 * @top: head of the doubly linked list
 * @n: value to be stored in new node
 *
 * Return: void
 */
void addnode(stack_t **top, int n)
{
	stack_t *new_node, *current = *top;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = current;
	new_node->prev = NULL;
	if (current)
		current->prev = new_node;
	*top = new_node;
}

/**
 * add_queue_node - adds a new node at the tail(bottom) of a doubly linked list
 *
 * @top: head of the doubly linked list
 * @n: value to be stored in new node
 *
 * Return: void
 */
void add_queue_node(stack_t **top, int n)
{
	stack_t *new_node, *current = *top;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	while (current && current->next)
		current = current->next;
	if (current)
	{
		current->next = new_node;
		new_node->prev = current;
	}
	else
	{
		(*top) = new_node;
		new_node->prev = NULL;
	}
}

/**
 * free_stack - free a double linked list stack implementation
 *
 * @top: pointer to ther top of the stack(head of linked list)
 *
 * Return: void
 */
void free_stack(stack_t *top)
{
	stack_t *current = top;

	while (top)
	{
		top = top->next;
		free(current);
		current = top;
	}
}
