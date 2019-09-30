#ifndef MONTY_H
#define MONTY_H

#define SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

int global_n;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

stack_t *global_head;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pall(stack_t **h, unsigned int line_number);
void push(stack_t **head, unsigned int line_number);
void pint(stack_t **h, unsigned int line_number);
void pop(stack_t **h, unsigned int line_number);
void swap(stack_t **h, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void divi(stack_t **head, unsigned int line_number);
void mult(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);

void fopen_err(char *var);
void op_err(int num, char *var);
void malloc_err(void);
void arg_check(char *arg1, unsigned int Ln);
void push_err(unsigned int Ln);

void input_checker(int ac);
FILE *file_to_ptr(char *filename);
void run(FILE *fp);
void find_and_run(char *copy, unsigned int line_number, stack_t **stack2ptr);

int _strcmp(char *s1, char *s2);
void free_list(stack_t *head);
int space_newline_finder(char buffer);

#endif
