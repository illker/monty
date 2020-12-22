#include "monty.h"

/**
 * pushq - add node at the end
 * @stack: pointer to head
 * @line_number: number of the new node
 */
void pushq(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	(void)line_number;
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlist(*stack);
		free(gv.tokens);
		fclose(gv.fp);
		exit(EXIT_FAILURE);
	}

	new->n = gv.g_n;
	new->next = NULL;
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}

	temp = *stack;

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = new;
	new->prev = temp;
}
