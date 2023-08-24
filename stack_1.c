#include "monty.h"

/**
 * stack_mod - computes the rest of the division of the top element with it's previous
 * @stack_top: pointer to head of stack (top node)
 * @line_number: the line number that contains the "mod" instruction
 * Return: void
 *
 * Description: will mod the top two elements and replace it with
 * one node contains the result
 */
void stack_mod(stack_t **stack_top, UNUSED unsigned int line_number)
{
	if (!stack_top || !*stack_top || !(*stack_top)->prev)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
    free_ctx();
		exit(EXIT_FAILURE);
	}

  if ((*stack_top)->n == 0)
  {
    fprintf(stderr, "L%u: division by zero\n", line_number);
    free_ctx();
    exit(EXIT_FAILURE);
  }

	(*stack_top)->prev->n %= (*stack_top)->n;
	*stack_top = (*stack_top)->prev;
	free((*stack_top)->next);
}
