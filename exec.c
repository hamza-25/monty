#include "monty.h"
void f_push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int value;

    if (!token)
    {
        fprintf(stderr, "Error: Missing argument for push at line %u\n", line_number);
        exit(1);
    }
    
    value = atoi(token);
    
    stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }
    
    new_node->n = value;
    new_node->next = *stack;
    *stack = new_node;
    top = new_node;
}
int exec(stack_t **stack, unsigned int num_line, char *line)
{
	instruction_t instru[] = {
		{"push", f_push},
		{NULL, NULL}
	};
	int index = 0, data;
	char *token;
	/*const char *cons_token;*/
	
	token = strtok(line, " \n\t$");
	while(token)
	{
		while(instru[index].opcode)
		{
			printf("instr\n");
			if (strcmp(instru[index].opcode, token) == 0)
			{
			token = strtok(NULL, " \n\t$");
			if (!token)
				return (0);
			instru[index].f(stack, num_line);
			break;
			}
			/*cons_token = token;
			if (atoi(cons_token) == 0)
				break;
			data = atoi(cons_token);
			printf("%d\n", data);*/
			index++;

		}
		token = strtok(NULL, " \n\t$");
	}

}
