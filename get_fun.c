#include "monty.h"

/**
 * get_function - Function to get pointer to functions
 * @str: Token to compare.
 * @line: line number read.
 * Return: Wild pointer.
 */

void (*get_function(char *str, unsigned int line))(stack_t **, unsigned int)
{
	short int i = 0;
	char *a = "stack", *b = "queue";
	instruction_t func[] = {
		{"nop", nop},
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div_},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"rotl", rotl},
		{"pstr", pstr},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (strcmp(str, b) == 0)
	{
		gv.state = 1;
		return (func[i].f);
	}
	else if (strcmp(str, a) == 0)
	{
		gv.state = 0;
		return (func[i].f);
	}
	while (func[i].opcode)
	{
		if (strcmp(func[i].opcode, str) == 0 || str[0] == '#')
			return (func[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, str);
	exit(EXIT_FAILURE);
}
