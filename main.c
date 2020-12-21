#include "monty.h"

/**
 * main - dsdsf
 * @argc: dfsdf
 * @argv: dfsdf
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char buff[1024], *buffer = buff;
	stack_t *stack;
	unsigned int lines = 1;

	stack = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	gv.fp = fopen(argv[1], "r");
	if (gv.fp)
	{
		while (fgets(buffer, 1024, (FILE *) gv.fp) != NULL)
		{
			gv.tokens = parse_buffer(buffer);
			if (gv.tokens[1])
				gv.g_n = atoi(gv.tokens[1]);
			get_function(gv.tokens[0], lines)(&stack, lines);
			lines++;
			free(gv.tokens);
		}
		fclose(gv.fp);
		free_dlist(stack);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (0);
}
