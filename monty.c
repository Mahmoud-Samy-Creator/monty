#include "monty.h"

CTX_t *CTX = NULL;

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	init_ctx();
	CTX->fd = fopen(av[1], "r");
	if (!CTX->fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	CTX->line_n = 1;
	while (1)
	{
		CTX->line = readfile(CTX->fd);
		if (!CTX->line)
		{
			break;
		}
		else if (strcmp(CTX->line, "\n") == 0)
		{
			CTX->line_n++;
			continue;
		}
		CTX->tokens = parseline(CTX->line, " \n");
		if (!CTX->tokens)
			break;
		if (*CTX->tokens)
			exec_instructions(&CTX->stack, CTX->line_n);
		free(CTX->line);
		CTX->line = NULL;
		free_dptr(CTX->tokens);
		CTX->tokens = NULL;
		CTX->line_n++;
	}
	free_ctx();
	return (0);
}
