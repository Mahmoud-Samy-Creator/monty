#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define UNUSED __attribute__((unused))

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct CTX_s - the interpreter context and it's members
 * @line_n: the line number that we excute it
 * @line: the line that proccess in it
 * @tokens: the strings in the @line
 * @stack: the main stack of the interpreter (monty)
 * @fd: pointer to file discriptor of the opened file
 *
 * Description: a structure that hold all important vars to
 * the interpreter while execute file
 */
typedef struct CTX_s
{
	int line_n;
	char *line;
	char **tokens;
	stack_t *stack;
	FILE *fd;
} CTX_t;


extern CTX_t *CTX;


/*          run.c            */
char *readfile(FILE *stream);
char **parseline(char *line, char *delim);
void exec_instructions(stack_t **stack, unsigned int line_number);


/*          utils.c            */
char *resize_ptr(char *ptr, int *old_size);
char **resize_dptr(char **dptr, int *old_size, int *old_ptr_size);
void free_dptr(char **dptr);
void init_ctx(void);
void free_ctx(void);


/*          stack.c            */
void free_stack(stack_t *stack);
void stack_push(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack_top, unsigned int line_number);
void stack_sub(stack_t **stack_top, unsigned int line_number);
void stack_div(stack_t **stack_top, UNUSED unsigned int line_number);


/*          stack_1.c          */
void stack_mod(stack_t **stack_top, UNUSED unsigned int line_number);


/*          stack_2.c          */
void stack_rotl(stack_t **stack_top, UNUSED unsigned int line_number);


/*          strdup.c          */
char *_strdup(char *str);

#endif

