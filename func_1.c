#include "monty.h"

/**
 * f_push - push items in the stack
 * @stack: the stack node
 * @line_number: line number from file interp
*/
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (!stack)
		exit(1);
	(void)line_number;
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(global_data.top);
		exit(1);
	}
	new_node->n = global_data.value;
	new_node->next = NULL;
	if (*stack)
		new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
	global_data.top = new_node;
}
/**
 * f_pall - print all items in stack
 * @stack: the stack node
 * @line_number: line number from file interp
*/

void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * f_pint - function that print number of the head
 * @line_number: number of line read from file
 * @stack: the stack node
*/

void f_pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(global_data.top), fclose(global_data.file), exit(1);
	}
	fprintf(stdout, "%d\n", global_data.value);
}

/**
 * f_pop - function that delete node from the head
 * @line_number: number of line read from file
 * @stack: the stack node
*/

void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(global_data.top), fclose(global_data.file), exit(1);
	}
	*stack = (*stack)->next;
	global_data.top = *stack;
	free(temp);
	temp = NULL;
}

/**
 * exec - function that loocking for opcode to execute
 * @line: line read from file
 * @num_line: number of lines from file
 * @stack: the stack node
 * @file: file to close if exit program
*/
void exec(stack_t **stack, unsigned int num_line, char *line, FILE *file)
{
	instruction_t instru[] = {
	{"push", f_push},
	{"pall", f_pall},
	{"pint", f_pint},
	{"pop", f_pop},
	{NULL, NULL}
	};
	int index;
	char *token;

	(void)file;
	token = strtok(line, " \n\t$");
	while (token)
	{
		index = 0;
		while (instru[index].opcode)
		{
			if (strcmp(instru[index].opcode, token) == 0)
			{
				if (strcmp(instru[index].opcode, "push") == 0)
				{
					token = strtok(NULL, " \n\t$");
					if (!token || atoi(token) == 0)
					{
						fprintf(stderr, "L%d: usage: push integer\n", num_line);
						free_stack(global_data.top), fclose(file), exit(1);
					}
					global_data.value = atoi(token);
				}
				instru[index].f(stack, num_line);
				break;
			}
			index++;
		}
		if (instru[index].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", num_line, token);
			free_stack(global_data.top), fclose(file), exit(1);
		}
		token = strtok(NULL, " \n\t$");
	}
}
