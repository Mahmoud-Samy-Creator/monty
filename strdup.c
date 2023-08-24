#include "monty.h"

/**
 * _strdup - simple clone to strdup function
 * @str: string
 * Return: pointer to dubplicated string
 *
 * Desciription: create clone to strdup to can use
 * with C89 UNIX standard
 */
char *_strdup(char *str)
{
	if (str)
	{
		int len = strlen(str);
		char *str2 = malloc(len * sizeof(char) + 1);

		if (str2)
		{
			strcpy(str2, str);
			return (str2);
		}
		return (NULL);
	}
	return (NULL);
}
