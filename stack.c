#include "monty.h"

/**
 * free_stack - to free stack
 * @stack: head of stack (top node)
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = NULL;

	while (stack)
	{
		temp = stack->prev;
		free(stack);
		stack = temp;
	}
}

/**
 * stack_push - push new element to stack
 * @stack_top: pointer to head of stack (top node)
 * @line_number: the line number that contains the "push" instruction
 * Return: void
 */
void stack_push(stack_t **stack_top, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!stack_top)
		fprintf(stderr, "stack is NULL\n");

	if (atoi(CTX->tokens[1]) == 0 && strcmp(CTX->tokens[1], "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_ctx();
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_ctx();
		exit(EXIT_FAILURE);
	}

	node->n = atoi(CTX->tokens[1]);
	node->next = NULL;

	if (!*stack_top)
	{
		*stack_top = node;
		node->prev = NULL;
		return;
	}

	(*stack_top)->next = node;
	node->prev = *stack_top;
	*stack_top = node;
}

/**
 * stack_pall - push new element to stack
 * @stack_top: pointer to head of stack (top node)
 * @line_number: the line number that contains the "pall" instruction
 * Return: void
 */
void stack_pall(stack_t **stack_top, UNUSED unsigned int line_number)
{
	stack_t *curr = NULL;

	curr = *stack_top;

	while (curr)
	{
		fprintf(stdout, "%d\n", curr->n);
		curr = curr->prev;
	}
}

/**
 * stack_sub - substract the the top element with it's previous
 * @stack_top: pointer to head of stack (top node)
 * @line_number: the line number that contains the "sub" instruction
 * Return: void
 *
 * Description: will sub the top two elements and replace it with
 * one node contains the result
 */
void stack_sub(stack_t **stack_top, UNUSED unsigned int line_number)
{
	if (!stack_top || !*stack_top || !(*stack_top)->prev)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_ctx();
		exit(EXIT_FAILURE);
	}

	(*stack_top)->prev->n -= (*stack_top)->n;
	*stack_top = (*stack_top)->prev;
	free((*stack_top)->next);
}

/**
 * stack_div - divides the the top element with it's previous
 * @stack_top: pointer to head of stack (top node)
 * @line_number: the line number that contains the "div" instruction
 * Return: void
 *
 * Description: will divide the top two elements and replace it with
 * one node contains the result
 */
void stack_div(stack_t **stack_top, UNUSED unsigned int line_number)
{
	if (!stack_top || !*stack_top || !(*stack_top)->prev)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_ctx();
		exit(EXIT_FAILURE);
	}

	if ((*stack_top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_ctx();
		exit(EXIT_FAILURE);
	}

	(*stack_top)->prev->n /= (*stack_top)->n;
	*stack_top = (*stack_top)->prev;
	free((*stack_top)->next);
}
