#include "monty.h"

/**
 * exec - executes the opcode
 *
 * @top: pointer to the top of the stack
 * @line_number: current of monty file line being executed
 *
 * Return: void
 */
void exec(stack_t **top, unsigned int line_number)
{
	instruction_t op_func[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(carrier.line, " \n\t");
	if (op && op[0] == '#')
		return;
	carrier.arg = strtok(NULL, " \n\t");
	while (op && op_func[i].opcode)
	{
		if (strcmp(op, op_func[i].opcode) == 0)
		{
			op_func[i].f(top, line_number);
			return;
		}
		i++;
	}
	if (op && op_func[i].opcode == NULL)
	{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(carrier.file);
		free(carrier.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
}
