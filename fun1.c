#include "monty.h"

/**
 * push - add node at start in a double linked list.
 * @stack: pointer to head.
 * @line_number: number of the new node.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return;

	new->n = global_variable;
	new->prev = NULL;

	if (*stack)
	{
		(*stack)->prev = new;
		new->next = *stack;
	}
	else
		new->next = NULL;
	*stack = new;
}

/**
 * pall - Print the stack.
 * @stack: pointer to head.
 * @line_number: number of the new node.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to head.
 * @line_number: Number of the new node.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
}

/**
 * pop - Pop node at start in a double linked list
 * @stack: Pointer to head.
 * @line_number: Number of the new node.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
		return;

	temp = *stack;

	if (temp->next)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
	free(temp);
}

/**
 * swap - Swap two top nodes.
 * @stack: Pointer to head.
 * @line_n: Number of the new node.
 */
void swap(stack_t **stack, unsigned int line_n)
{
	stack_t *h, *node_2;

	h = *stack;
	if (*stack && (*stack)->next)
	{
		node_2 = h->next; /* Address of second node*/
		h->prev = h->next;
		h->next = node_2->next;
		if (node_2->next) /* if node_3 exist */
			(node_2->next)->prev = h;
		node_2->prev = NULL;
		node_2->next = h;
		*stack = node_2;
	}
	else
	{
		fprintf(stderr, "L %d: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
}
