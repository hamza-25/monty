#include "monty.h"
/**
 * free_stack - func that free linked list
 * @top: head of the list
*/
void free_stack(stack_t *top)
{
	stack_t *temp;

	while (top)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
}

/**
 * f_swap - function that swap values in linked list
 * @line_number: number of line read from file
 * @stack: the stack node
*/

void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *current = *stack;
	int count = 0;

	while (current)
	{
		current = current->next;
		count++;
	}
	if (count <= 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(global_data.top), fclose(global_data.file), exit(1);
	}
	(void)line_number;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	temp->prev = NULL;
	temp->next->prev = (*stack);
	temp->next = (*stack);
	(*stack) = temp;
	global_data.top = *stack;
}
