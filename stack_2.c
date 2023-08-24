#include "monty.h"

/**
 * stack_rotl - swap top of the stack with botton of stack
 * and remove top element
 * @stack_top: pointer to head of stack (top node)
 * @line_number: the line number that contains the "rotl" instruction
 * Return: void
 */
void stack_rotl(stack_t **stack_top, UNUSED unsigned int line_number)
{
	stack_t *curr = NULL;

	if (!stack_top || !*stack_top)
		return;

	curr = *stack_top;

	while (curr->prev)
		curr = curr->prev;

	curr->n = (*stack_top)->n;
	curr = *stack_top;
	*stack_top = (*stack_top)->prev;
	free(curr);
}

/**
 * stack_pchar - A function to print the last element of stack as a char
 * @stack_top: stack head (top element)
 * @line_number: The line counter
 * Return: void
 */
void stack_pchar(stack_t **stack_top, unsigned int line_number)
{
	if (!stack_top || !(*stack_top))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_ctx();
		exit(EXIT_FAILURE);
	}
	else if ((*stack_top)->n < 0 || (*stack_top)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_ctx();
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack_top)->n);
}
