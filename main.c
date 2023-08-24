#include "monty.h"

data_t global_data = {0, NULL, NULL};

/**
 * main - entry point
 * @argc: numbers of args
 * @argv: args vector
 * Return: int
*/

int main(int argc, char *argv[])
{
	FILE *fd;
	char line[256];
	stack_t *stack = NULL;
	int counter = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(1);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(1);
	}
	global_data.file = fd;
	while (fgets(line, sizeof(line), fd) != NULL)
	{
		exec(&stack, counter, line, fd);
		counter++;
	}
	free_stack(global_data.top);
	fclose(fd);
	return (0);
}
