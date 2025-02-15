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

	gv.tokens = NULL;
	gv.g_n = 0;
	stack = NULL;
	gv.state = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	gv.fp = fopen(argv[1], "r");
	if (gv.fp)
	{
		while (fgets(buffer, 1024, (FILE *) gv.fp) != NULL)
		{
			if (empty_str(buffer) == 1)
			{
				gv.tokens = parse_buffer(buffer);
				get_function(gv.tokens[0], lines)(&stack, lines);
				free(gv.tokens);
			}
			lines++;
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
