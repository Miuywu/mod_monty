#include "monty.h"

/**
 * add - finds the sum of the top 2 nodes on stack
 * @head: top of stack
 * @line_number: line number where error occured
 */

void add(stack_t **head, unsigned int line_number)
{
	int sum = 0;
	stack_t *deleteNode;

	if (!*head || !((*head)->next))
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	deleteNode = *head;
	*head = (*head)->next;
	(*head)->n = sum;

	pop(&deleteNode, line_number);
}

/**
 * sub - finds the difference of the top 2 nodes on stack
 * @head: top of stack
 * @line_number: line number where error occured
 */

void sub(stack_t **head, unsigned int line_number)
{
	int difference = 0;
	stack_t *deleteNode;

	if (!*head || !((*head)->next))
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	difference = -((*head)->n) + (*head)->next->n;
	deleteNode = *head;
	*head = (*head)->next;
	(*head)->n = difference;

	pop(&deleteNode, line_number);
}

/**
 * divi - finds the quotient of the top 2 nodes on stack
 * @head: top of stack
 * @line_number: line number where error occured
 */

void divi(stack_t **head, unsigned int line_number)
{
	int quotient = 0;
	stack_t *deleteNode;

	if (!*head || !((*head)->next))
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = (*head)->n / (*head)->next->n;
	deleteNode = *head;
	*head = (*head)->next;
	(*head)->n = quotient;

	pop(&deleteNode, line_number);
}

/**
 * mult - finds the product of the top 2 nodes on stack
 * @head: top of stack
 * @line_number: line number where error occured
 */

void mult(stack_t **head, unsigned int line_number)
{
	int product = 0;
	stack_t *deleteNode;

	if (!*head || !((*head)->next))
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	product = (*head)->n * (*head)->next->n;
	deleteNode = *head;
	*head = (*head)->next;
	(*head)->n = product;

	pop(&deleteNode, line_number);
}

/**
 * mod - finds the remainder of the top 2 nodes on stack
 * @head: top of stack
 * @line_number: line number where error occured
 */

void mod(stack_t **head, unsigned int line_number)
{
	int quotient = 0;
	stack_t *deleteNode;

	if (!*head || !((*head)->next))
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = (*head)->n % (*head)->next->n;
	deleteNode = *head;
	*head = (*head)->next;
	(*head)->n = quotient;

	pop(&deleteNode, line_number);
}
