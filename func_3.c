#include "monty.h"

/**
 * f_div - function that div first node on second
 * @line_number: number of line read from file
 * @stack: the stack node
*/
void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp = *stack;
	int count = 0, keep;

	while (current)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(global_data.top), fclose(global_data.file), exit(1);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(global_data.top), fclose(global_data.file), exit(1);
	}
	keep = (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n = ((*stack)->n) / keep;
	global_data.top = *stack;
	free(temp);
}

/**
 * f_mul - function that multip first node on second
 * @line_number: number of line read from file
 * @stack: the stack node
 */

void f_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp = *stack;
	int count = 0, keep;

	while (current)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(global_data.top), fclose(global_data.file), exit(1);
	}
	keep = (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n = ((*stack)->n) * keep;
	global_data.top = *stack;
	free(temp);
}
