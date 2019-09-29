#include "monty.h"

/**
 * fopen_err - prints error message and exits
 * @var: name of file
 */

void fopen_err(char *var)
{
	write(STDERR_FILENO, "Error: Can't open file ", 23);
	write(STDERR_FILENO, var, strlen(var));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
/**
 * arg_check - checks for invalid arguments for push
 * @arg: name of file
 * @Ln: int
 */

void arg_check(char *arg0, char *arg1, unsigned int Ln)
{
	int a;

	(void) arg0;
	if (arg1 == NULL)
	{
		/*free(arg0);*/
		push_err(Ln);
	}
	for (a = 0; arg1[a] != '\0'; a++)
	{
		if (a == 0 && arg1[a] == '-')
		{
			if (arg1[a + 1] == '\0')
			{
				/*free(arg0);
				  free(arg1);*/
				push_err(Ln);
			}
		}
		else if (arg1[a] < 48 || arg1[a] > 57)
                {
			/*free(arg0);
			  free(arg1);*/
			push_err(Ln);
		}
	}
}
/**
 * push_err - prints push error and exits
 * @Ln: int
 */

void push_err(unsigned int Ln)
{
	dprintf(STDERR_FILENO, "L%d: usage: push integer\n", Ln);
	exit(EXIT_FAILURE);
}
