#include "monty.h"

stack_t *top = NULL;
int value;

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
	while (fgets(line, sizeof(line), fd) != NULL)
	{
		exec(&stack, counter, line, fd);
		counter++;
	}
	free_stack(top);
	fclose(fd);
	return (0);
}
