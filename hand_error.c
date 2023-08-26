#include "monty.h"

/**
 * err_msg - func print errors
 * @msg: content of error
 * @line: line where the error happened
 */

void err_msg(char *msg, int line)
{
	fprintf(stderr, "L%d: %s\n", line, msg);
	free_stack(global_data.top), fclose(global_data.file), exit(1);
}

/**
 * err_msg_tok - func print errors
 * @msg: content of error
 * @line: line where the error happened
 * @token: token that occur the error
 */

void err_msg_tok(char *msg, int line, char *token)
{
	fprintf(stderr, "L%d: %s %s\n", line, msg, token);
	free_stack(global_data.top), fclose(global_data.file), exit(1);
}
