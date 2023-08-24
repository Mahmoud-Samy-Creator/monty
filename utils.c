#include "monty.h"

/**
 * resize_ptr - simple clone to realloc funtion
 * to resize char pointers without losing old data
 * @ptr: the pointer that will resize it
 * @old_size: old size of the pointer
 *
 * Return: new resized pointer
 */
char *resize_ptr(char *ptr, int *old_size)
{
	char *temp = NULL;

	temp = malloc(*old_size * 2);
	memcpy(temp, ptr, *old_size);
	*old_size *= 2;

	free(ptr);
	return (temp);
}


/**
 * resize_dptr - resize double pointer
 * without losing old data
 * to resize char pointers without losing old data
 * @dptr: the double pointer that will resize it
 * @old_size: old size of the double pointer
 * @old_ptr_size: old size of each pointer
 *
 * Return: new resized double pointer
 */
char **resize_dptr(char **dptr, int *old_size, int *old_ptr_size)
{
	char **temp = NULL;
	int i;

	temp = (char **)malloc(*old_size * 2);
	for (i = 0; dptr[i] != NULL; i++)
	{
		temp[i] = malloc(*old_ptr_size);
		memcpy(temp[i], dptr[i], *old_ptr_size);

	}
	return (temp);
}


/**
 * free_dptr - free double pointer
 * @dptr: double pointer
 * Return: void
 */
void free_dptr(char **dptr)
{
	int i = 0;

	for (i = 0; dptr[i] != NULL; i++)
	{
		free(dptr[i]);
	}
	free(dptr);
}

/**
 * init_ctx - initialize CTX members
 * Return: void
 */
void init_ctx(void)
{
	CTX = malloc(sizeof(CTX_t));
	if (!CTX)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	CTX->line_n = 0;
	CTX->tokens = NULL;
	CTX->line = NULL;
	CTX->stack = NULL;
	CTX->fd = NULL;
}

/**
 * free_ctx - free CTX members
 * Return: void
 */
void free_ctx(void)
{
	if (CTX->line)
	{
		free(CTX->line);
		CTX->line = NULL;
	}
	if (CTX->tokens)
		free_dptr(CTX->tokens);

	if (CTX->fd)
		fclose(CTX->fd);

	if (CTX->stack)
		free_stack(CTX->stack);

	free(CTX);
}
