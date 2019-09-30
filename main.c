#include "monty.h"

/**
 * main - entry point
 * @ac: argument counter
 * @av: argument vector
 * Return: Status either Success/Failure
 */
int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	file = file_to_ptr(av[1]);
	run(file);
	fclose(file);
	if (global_head)
		free_list(global_head);
	return (EXIT_SUCCESS);
}
/**
 * file_to_ptr - returns a ptr to buffer which stores contents of file
 * @filename: arg[1]
 * Return: buffer
 */
FILE *file_to_ptr(char *filename)
{
	FILE *fp;

	fp = fopen(filename, "r");
	if (fp == NULL)
		fopen_err(filename);
	return (fp);
}
/**
 * run - loops thru file's line and attempts to run them
 * @fp: file ptr
 * Return: Status either Success/Failure
 */

void run(FILE *fp)
{
	size_t len = 0;
	unsigned int line_number;
	char *buffer = NULL;
	stack_t *stack = NULL, **stack2ptr = &stack;
	int counter = 0, i;

	for (line_number = 1; getline(&buffer, &len, fp) != -1; line_number++)
	{
		if (strlen(buffer) == 1)
			continue;
		while (space_newline_finder(*buffer) && *buffer != '\n')
		{	buffer++;
			counter++;
		}
		if (*buffer == '\n')
			continue;
		for (i = 0; i < counter; i++)
			buffer--;
		find_and_run(buffer, line_number, stack2ptr);
	}
	if (buffer)
		free(buffer);
}

/**
 * find_and_run - compares arg[0] and available fn's and runs if success
 * @copy: ptr to physical copy of string stored at buffer
 * @line_number: line number in file
 * @stack2: double ptr to stack
 * Return: void
 */

void find_and_run(char *copy, unsigned int line_number, stack_t **stack2)
{
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divi},
		{"mul", mult},
		{"mod", mod},
		{NULL, NULL}
	};
	char *arg0, *arg1;
	int a;

	arg0 = strtok(copy, " \n\0");
	if (_strcmp(funcs[0].opcode, arg0) == 0)
	{
		arg1 = strtok(NULL, " \n\0");
		arg_check(arg1, line_number);
		global_n = atoi(arg1);
		(funcs[0].f)(stack2, line_number);
		return;
	}
	for (a = 1; funcs[a].opcode; a++)
		if (_strcmp(arg0, funcs[a].opcode) == 0)
		{
			(funcs[a].f)(stack2, line_number);
			break;
		}
	if (funcs[a].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, arg0);
		exit(EXIT_FAILURE);
	}
}
/**
 * _strcmp - takes in 2 strings and compares
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: difference of non-matching char's ASCII value
 */

int _strcmp(char *s1, char *s2)
{
	int a, b, c, d, e;
	for (a = 0; s1[a]; a++)
		;
	for (b = 0; s2[b]; b++)
		;
	c = b;
	if (a >= b)
		c = a;
	for (d = 0; s1[d] && s2[d]; d++, c--)
	{
		if (s1[d] != s2[d])
			return (s1[d] - s2[d]);
		if (!s1[d + 1])
			e = 1;
		if (!s2[d + 1])
			e = 2;
	}
	if (c > 0)
	{
		if (e == 1)
			if (s2[d] != '\n' && s2[d] != '\0' && s2[d] != ' ')
				return (5);
		if (e == 2)
                        if (s1[d] != '\n' && s1[d] != '\0' && s1[d] != ' ')
                                return (5);
	}
	return (0);
}
