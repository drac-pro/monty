#include "monty.h"

carrier_t carrier = {NULL, NULL, NULL, 0};
/**
 * main - monty program entry point
 *
 * @argc: number of arguments passed to the monty program
 * @argv: pointer to the arguments
 *
 * Return: 0 (SUCCESS)
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	char *line = NULL;
	stack_t *top = NULL;
	ssize_t lines_read = 1;
	size_t size = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	carrier.file = file;
	while (lines_read > 0)
	{
		line = NULL;
		lines_read = getline(&line, &size, file);
		carrier.line = line;
		line_number++;
		if (lines_read > 0)
		{
			exec(&top, line_number);
		}
		free(line);
	}
	free_stack(top);
	fclose(file);
	return (0);
}
