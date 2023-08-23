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
