#include "monty.h"

/**
 * stack_nop - A function doesn't do anything
 * @stack: ptr to ptr of the stack elements
 * @line_number: The line counter
 * Return: void
 */
void stack_nop(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{

}

/**
 * stack_swap - A function swaps 2 elements of stack
 * @stack: ptr ot ptr of the stack elements
 * @line_number: The line counter
 * Return: void
 */
void stack_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int item;

	if ((*stack) == NULL || stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	item = temp->n;
	temp->n = (*stack)->n;
	(*stack)->n = item;
}
/**
 * stack_pop - A function pop last element of stack
 * @stack: ptr ot ptr of the stack elements
 * @line_number: The line counter
 * Return: void
 */
void stack_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = (*stack);

	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_ctx();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->prev;
	free(curr);
}

/**
 * stack_pint - A function to print the last element of stack
 * @stack: ptr ot ptr of the stack elements
 * @line_number: The line counter
 * Return: void
 */
void stack_pint (stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_ctx();
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", curr->n);
}

/**
 * stack_mod - computes the rest of the division
 * of the top element with it's previous
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
