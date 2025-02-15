#include "monty.h"

/**
 * nop - doesn’t do anything.
 * @stack: Double pointer with address to double linked list stack.
 * @line_number: number of line.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to stack
 * @line_number: line number of instruction
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top;

	(void)line_number;

	if (stack && *stack && (*stack)->next)
	{
		temp = *stack;
		top = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;

		while (temp->next)
			temp = temp->next;

		temp->next = top;
		top->next = NULL;
		top->prev = temp;
	}

}

/**
 * pstr - print a string.
 * @stack: pointer to stack
 * @line_number: line number of instruction
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;
	int num = 0;

	temp = *stack;
	for (; temp; temp = temp->next)
	{
		num = temp->n;
		if (num != 0 && ((num >= 'a' && num <= 'z') || (num >= 'A' && num <= 'Z')))
			putchar(num);
		else
			break;
	}
	putchar('\n');
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ntemp;

	(void)line_number;

	if (stack && *stack && (*stack)->next)
	{
		ntemp = *stack;

		while (ntemp->next)
			ntemp = ntemp->next;

		ntemp->prev->next = NULL;
		ntemp->prev = NULL;
		ntemp->next = *stack;
		(*stack)->prev = ntemp;
		*stack = ntemp;
	}
}

