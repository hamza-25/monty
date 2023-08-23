#include "monty.h"
/**
 *
 *
 *
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

