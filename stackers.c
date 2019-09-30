#include "monty.h"

/**
 * push - adds new node to the top of stack
 * @head: top of stack
 * @line_number: line where error occured
 */

void push(stack_t **head, unsigned int line_number)
{
	int n = global_n;
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	global_head = new;
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc error\n");
	}
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	if (*head)
	{
		new->next = *head;
		(*head)->prev = new;
	}
	*head = new;
}

/**
 * pall - prints values of all nodes
 * @h: top of stack
 * @line_number: line where error occured
 */

void pall(stack_t **h, unsigned int line_number)
{
	stack_t *curr = *h;

	(void)line_number;
	if (!*h)
		return;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * pop - deletes top node on stack
 * @h: top of stack
 * @line_number: line where error occured
 */

void pop(stack_t **h, unsigned int line_number)
{
	stack_t *deleting;

	if (*h == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		deleting = *h;
		*h = (*h)->next;
		global_head = *h;
		free(deleting);
		if (*h != NULL)
			(*h)->prev = NULL;
	}

}

/**
 * pint - prints the value of top-most node
 * @h: node
 * @line_number: line where error occured
 */

void pint(stack_t **h, unsigned int line_number)
{
	if (!*h)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}

/**
 * swap - prints the int at node
 * @h: node
 * @line_number: line where error occured
 */

void swap(stack_t **h, unsigned int line_number)
{
	int nextN;

	if (!*h || !((*h)->next))
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	nextN = (*h)->next->n;
	(*h)->next->n = (*h)->n;
	(*h)->n = nextN;
}
