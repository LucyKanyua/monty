#include "monty.h"
#include <string.h>

void process_opcode(stack_t **stack, char *opcode, unsigned int line_number);
char *_value;

/**
 * main - main entry point
 * @argc: list of arguments
 * @argv: array of arguments
 * Return: 0 on success and EXIT_FAILURE on fail
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char buffer[1024], *s, *str, *token, *delim = " \n";
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((s = fgets(buffer, sizeof(buffer), fp)))
	{
		str = s;
		token = strtok(str, delim);
		_value = strtok(NULL, delim);

		if (token != NULL && token[0] != '#')
			process_opcode(&stack, token, line_number);

		if (buffer[strlen(s) - 1] == '\n')
			line_number++;
		free(str);
	}
	fclose(fp);
	free(stack);
	return (0);
}

/**
 * process_opcode - analyses the inputed code and passes it to right handler
 * @stack: pointer to stack
 * @opcode: the opcode
 * @line_number: the line with the instruction
 * Return: void
 */
void process_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	int len, fnd = 0, i = 0;

	instruction_t stack_ops[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"stack", opcode_stack},
		{"nop", opcode_nop},
		{"add", opcode_add},
	};

	len = sizeof(stack_ops) / sizeof(instruction_t);
	while (i < len)
	{
		if (strcmp(opcode, stack_ops[i].opcode) == 0)
		{
			fnd = 1;
			stack_ops[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (!fnd)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
