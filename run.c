#include "monty.h"


/**
 * readfile - read line by line from @stream
 * @stream: file file that will read from
 * Return: return the next line every call of the funtion
 */
char *readfile(FILE *stream)
{
	int ptr_size = 1024;
	char *line = NULL, c;
	int i = 0;

	line = (char *)malloc(ptr_size);
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	c = fgetc(stream);
	if (c == EOF || c == -1)
	{
		free(line);
		return (NULL);
	}
	else if (c == '\n')
	{
		free(line);
		line = NULL;
		return ("\n");
	}
	else
		line[i] = c;

	for (i = 1; ; i++)
	{
		if (i == ptr_size - 1)
			line = resize_ptr(line, &ptr_size);
		c = fgetc(stream);
		if (c == EOF || c == '\n' || c == -1)
		{
			line[i] = '\0';
			break;
		}
		else
			line[i] = c;
	}
	return (line);
}

/**
 * parseline - parse line to maltiple strings
 * @line: the string that will parse
 * @delim: delemiters
 * Return: double pointer that contains each string in line
 */
char **parseline(char *line, char *delim)
{
	int i = 0;
	int ptr_size = 1024, dptr_size = 16;
	char *line_copy;
	char **tokens;

	tokens = malloc(sizeof(char *) * dptr_size);
	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	line_copy = _strdup(line);
	tokens[0] = _strdup(strtok(line_copy, delim));

	for (i = 1; tokens[i - 1] != NULL; i++)
	{
		if (i == dptr_size - 1)
			resize_dptr(tokens, &dptr_size, &ptr_size);

		tokens[i] = _strdup(strtok(NULL, delim));
	}

	free(line_copy);
	return (tokens);
}


/**
 * exec_instructions - execute monty instructions
 * @stack: pointer to the head of stack (top node)
 * @line_number: the line number of the monty file
 *
 * Return: 0 if seccess else 1
 */
void exec_instructions(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t keywords[] = {
		{"push", stack_push}, {"pall", stack_pall},
		{"swap", stack_swap}, {"nop", stack_nop},
		{"sub", stack_sub}, {"div", stack_div},
		{"mod", stack_mod}, {"rotl", stack_rotl},
		{"pop", stack_pop}, {"pint", stack_pint},
		{"pchar", stack_pchar}, {"mul", stack_mul},
		{NULL, NULL}};

	if (!CTX->tokens)
		return;

	for (i = 0; keywords[i].opcode != NULL; i++)
	{
		if (strcmp(keywords[i].opcode, CTX->tokens[0]) == 0)
		{
			keywords[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, CTX->tokens[0]);
	free_ctx();
	exit(EXIT_FAILURE);
}
