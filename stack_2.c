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
	*stack_top = (*stack_top)->prev;
}
