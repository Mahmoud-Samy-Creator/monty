#include "monty.h"

/**
 * isnum - check if @string is number or not
 * @str: string that will checked
 * Return: 1 if @str a number 0 else
 */
int isnum(char *str)
{
	unsigned int i;

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != '-' && str[i] != '+' && isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}
